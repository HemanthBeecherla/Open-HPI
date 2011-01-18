/*      -*- c++ -*-
 *
 * Copyright (c) 2011 by Pigeon Point Systems.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  This
 * file and program are licensed under a BSD style license.  See
 * the Copying file included with the OpenHPI distribution for
 * full licensing terms.
 *
 * Authors:
 *     Anton Pak <avpak@pigeonpoint.com>
 *
 */

#include <list>

#include <oh_error.h>
#include <oh_utils.h>

#include "hpi.h"
#include "hpi_xml_writer.h"


/***************************************************
 * Data Types
 ***************************************************/
struct Resource
{
    SaHpiRptEntryT rpte;
    SaHpiUint32T rdr_update_count;
    std::list<SaHpiRdrT> instruments;
};


/***************************************************
 * Helper Functions
 ***************************************************/
static bool GetDomainInfo( SaHpiSessionIdT sid, SaHpiDomainInfoT& di )
{
    SaErrorT rv;
    rv = saHpiDomainInfoGet( sid, &di );
    if ( rv != SA_OK ) {
        CRIT( "saHpiDomainInfoGet returned %s", oh_lookup_error( rv ) );
    }
    return ( rv == SA_OK );
}

static bool FetchDrt( SaHpiSessionIdT sid,
                      SaHpiDomainInfoT& di,
                      std::list<SaHpiDrtEntryT>& drt )
{
    SaHpiDomainInfoT di2;

    do {
        drt.clear();

        bool rc;

        rc = GetDomainInfo( sid, di );
        if ( !rc ) {
            return false;
        }

        SaHpiEntryIdT id, next_id;
        SaHpiDrtEntryT drte;
        id = SAHPI_FIRST_ENTRY;
        while ( id != SAHPI_LAST_ENTRY ) {
            SaErrorT rv;
            rv = saHpiDrtEntryGet( sid, id, &next_id, &drte );
            if ( rv == SA_ERR_HPI_NOT_PRESENT ) {
                break;
            }
            if ( rv != SA_OK ) {
                drt.clear();
                CRIT( "saHpiDrtEntryGet returned %s", oh_lookup_error( rv ) );
                return false;
            }
            drt.push_back( drte );
            id = next_id;
        }

        rc = GetDomainInfo( sid, di2 );
        if ( !rc ) {
            drt.clear();
            return false;
        }

    } while ( di.DrtUpdateCount != di2.DrtUpdateCount );

    return true;
}

static SaHpiUint32T GetRdrUpdateCounter( SaHpiSessionIdT sid, SaHpiResourceIdT rid )
{
    SaHpiUint32T cnt;
    SaErrorT rv = saHpiRdrUpdateCountGet( sid, rid, &cnt );
    if ( rv != SA_OK ) {
        CRIT( "saHpiRdrUpdateCountGet %s", oh_lookup_error( rv ) );
        return 0;
    }
    return cnt;
}

static bool FetchInstruments( SaHpiSessionIdT sid,
                              Resource& resource )

{
    SaErrorT rv;
    SaHpiResourceIdT rid = resource.rpte.ResourceId;
    SaHpiUint32T& cnt = resource.rdr_update_count;
    SaHpiUint32T cnt2;

    do {
        resource.instruments.clear();
        cnt = GetRdrUpdateCounter( sid, rid );

        SaHpiEntryIdT id, next_id;
        SaHpiRdrT rdr;
        id = SAHPI_FIRST_ENTRY;
        while ( id != SAHPI_LAST_ENTRY ) {
            rv = saHpiRdrGet( sid, rid, id, &next_id, &rdr );
            if ( rv == SA_ERR_HPI_NOT_PRESENT ) {
                break;
            }
            if ( rv != SA_OK ) {
                resource.instruments.clear();
                CRIT( "saHpiRdrGet returned %s", oh_lookup_error( rv ) );
                return false;
            }
            resource.instruments.push_back( rdr );
            id = next_id;
        }

        cnt2 = GetRdrUpdateCounter( sid, rid );

    } while ( cnt != cnt2 );

    return true;
}

static bool FetchResources( SaHpiSessionIdT sid,
                            SaHpiDomainInfoT& di,
                            std::list<Resource>& rpt )
{
    SaHpiDomainInfoT di2;

    do {
        rpt.clear();

        bool rc;

        rc = GetDomainInfo( sid, di );
        if ( !rc ) {
            return false;
        }

        SaHpiEntryIdT id, next_id;
        Resource resource;
        id = SAHPI_FIRST_ENTRY;
        while ( id != SAHPI_LAST_ENTRY ) {
            SaErrorT rv;
            rv = saHpiRptEntryGet( sid, id, &next_id, &resource.rpte );
            if ( rv == SA_ERR_HPI_NOT_PRESENT ) {
                break;
            }
            if ( rv != SA_OK ) {
                rpt.clear();
                CRIT( "saHpiRptEntryGet returned %s", oh_lookup_error( rv ) );
                return false;
            }
            rc = FetchInstruments( sid, resource );
            if ( !rc ) {
                break;
            }
            rpt.push_back( resource );
            id = next_id;
        }

        rc = GetDomainInfo( sid, di2 );
        if ( !rc ) {
            rpt.clear();
            return false;
        }

    } while ( di.RptUpdateCount != di2.RptUpdateCount );

    return true;
}

static bool FetchDat( SaHpiSessionIdT sid,
                      SaHpiDomainInfoT& di,
                      std::list<SaHpiAlarmT>& dat )
{
    SaHpiDomainInfoT di2;

    do {
        dat.clear();

        bool rc;

        rc = GetDomainInfo( sid, di );
        if ( !rc ) {
            return false;
        }

        SaHpiAlarmT a;
        a.AlarmId = SAHPI_FIRST_ENTRY;
        while ( true ) {
            SaErrorT rv;
            rv = saHpiAlarmGetNext( sid, SAHPI_ALL_SEVERITIES, SAHPI_FALSE, &a );
            if ( rv == SA_ERR_HPI_NOT_PRESENT ) {
                break;
            }
            if ( rv != SA_OK ) {
                dat.clear();
                CRIT( "saHpiDatEntryGet returned %s", oh_lookup_error( rv ) );
                return false;
            }
            dat.push_back( a );
        }

        rc = GetDomainInfo( sid, di2 );
        if ( !rc ) {
            dat.clear();
            return false;
        }

    } while ( di.DatUpdateCount != di2.DatUpdateCount );

    return true;
}


/***************************************************
 * class cHpi
 ***************************************************/
cHpi::cHpi( SaHpiDomainIdT did )
    : m_initialized( false ),
      m_opened( false ),
      m_did( did ),
      m_sid( 0 )
{
    // empty
}

cHpi::~cHpi()
{
    Close();
}

bool cHpi::Open()
{
    if ( m_opened ) {
        return true;
    }

    SaErrorT rv;

    if ( !m_initialized ) {
        rv = saHpiInitialize( SAHPI_INTERFACE_VERSION, 0, 0, 0, 0 );
        if ( rv != SA_OK ) {
            CRIT( "saHpiInitialize returned %s", oh_lookup_error( rv ) );
            return false;
        }
        m_initialized = true;
    }
    rv = saHpiSessionOpen( m_did, &m_sid, 0 );
    if ( rv != SA_OK ) {
        CRIT( "saHpiSessionOpen returned %s", oh_lookup_error( rv ) );
        return false;
    }
    m_opened = true;
    rv = saHpiDiscover( m_sid );
    if ( rv != SA_OK ) {
        CRIT( "saHpiDiscover returned %s", oh_lookup_error( rv ) );
        return false;
    }

    return true;
}

void cHpi::Close()
{
    if ( m_opened ) {
        saHpiSessionClose( m_sid );
        m_sid = 0;
        m_opened = false;
    }
    if ( m_initialized ) {
        saHpiFinalize();
        m_initialized = false;
    }
}

bool cHpi::Dump( cHpiXmlWriter& writer )
{
    bool rc;

    writer.Begin();

    writer.VersionNode( saHpiVersionGet() );

    SaHpiDomainInfoT di;
    rc = GetDomainInfo( m_sid, di );
    if ( !rc ) {
        return false;
    }

    writer.BeginDomainNode( di );

    SaHpiDomainInfoT drt_di;
    std::list<SaHpiDrtEntryT> drt;
    rc = FetchDrt( m_sid, drt_di, drt );
    if ( !rc ) {
        return false;
    }
    writer.BeginDrtNode( drt_di );
    while ( !drt.empty() ) {
        writer.DrtEntryNode( drt.front() );
        drt.pop_front();
    }
    writer.EndDrtNode();

    SaHpiDomainInfoT rpt_di;
    std::list<Resource> rpt;
    rc = FetchResources( m_sid, rpt_di, rpt );
    if ( !rc ) {
        return false;
    }
    writer.BeginRptNode( rpt_di );
    while ( !rpt.empty() ) {
        Resource& resource = rpt.front();
        writer.BeginResourceNode( resource.rpte, resource.rdr_update_count );

        if ( resource.rpte.ResourceCapabilities & SAHPI_CAPABILITY_EVENT_LOG ) {
            writer.BeginEventLogNode();
            writer.EndEventLogNode();
        }

        std::list<SaHpiRdrT>& instruments = resource.instruments;
        while ( !instruments.empty() ) {
            writer.BeginInstrumentNode( instruments.front() );
            writer.EndInstrumentNode();
            instruments.pop_front();
        }

        writer.EndResourceNode();
        rpt.pop_front();
    }
    writer.EndRptNode();

    writer.BeginDomainEventLogNode();
    writer.EndDomainEventLogNode();

    SaHpiDomainInfoT dat_di;
    std::list<SaHpiAlarmT> dat;
    rc = FetchDat( m_sid, dat_di, dat );
    if ( !rc ) {
        return false;
    }
    writer.BeginDatNode( dat_di );
    while ( !dat.empty() ) {
        writer.AlarmNode( dat.front() );
        dat.pop_front();
    }
    writer.EndDatNode();

    writer.EndDomainNode();

    writer.End();

    return true;
}
