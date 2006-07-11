/*      -*- linux-c -*-
 *
 * (C) Copyright IBM Corp. 2003, 2006
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. This
 * file and program are licensed under a BSD style license. See
 * the Copying file included with the OpenHPI distribution for
 * full licensing terms.
 *
 * Author(s):
 *      Sean Dague <http://dague.net/sean>
 *      Renier Morales <renierm@users.sf.net>
 *      Steve Sherman <stevees@us.ibm.com>
 */

#include <snmp_bc_plugin.h>

/**************************************************************************
 *                        Resource Definitions
 **************************************************************************/

/* BCT has different OID for System Health */
struct snmp_rpt snmp_bc_rpt_array_bct[] = {
        /* BladeCenter Chassis */
        {
                .rpt = {
                        .ResourceInfo = {
                                .ManufacturerId = IBM_MANUFACTURING_ID,
                        },
                        .ResourceEntity = {
                                .Entry[0] =
                                {
                                        .EntityType = SAHPI_ENT_ROOT,
                                        .EntityLocation = 0,
                                }
                        },
                        .ResourceCapabilities = SAHPI_CAPABILITY_CONTROL |
                                                SAHPI_CAPABILITY_INVENTORY_DATA |
                                                SAHPI_CAPABILITY_RDR |
                                                SAHPI_CAPABILITY_RESOURCE |
                                                SAHPI_CAPABILITY_SENSOR,
                        .ResourceSeverity = SAHPI_CRITICAL,
			.ResourceFailed = SAHPI_FALSE,
                },
                .res_info = {
                        .mib = {
                                .OidHealth = ".1.3.6.1.4.1.2.3.51.2.2.9.1.0",
                                .HealthyValue = 255,
                                .OidReset = '\0',
                                .OidPowerState = '\0',
                                .OidPowerOnOff = '\0',
				.OidUuid = ".1.3.6.1.4.1.2.3.51.2.2.21.1.1.4.0",
				.OidResourceWidth = '\0',
                        },
			.cur_state = 0,
			.prev_state = 0,
                        .event_array = {
                                {},
                        },
                },
                .comment = "BladeCenter Chassis",
        },

        {} /* Terminate array with a null element */	
};

struct snmp_rpt snmp_bc_rpt_array[] = {
        /* BladeCenter Chassis */
        {
                .rpt = {
                        .ResourceInfo = {
                                .ManufacturerId = IBM_MANUFACTURING_ID,
                        },
                        .ResourceEntity = {
                                .Entry[0] =
                                {
                                        .EntityType = SAHPI_ENT_ROOT,
                                        .EntityLocation = 0,
                                }
                        },
                        .ResourceCapabilities = SAHPI_CAPABILITY_CONTROL |
                                                SAHPI_CAPABILITY_INVENTORY_DATA |
                                                SAHPI_CAPABILITY_RDR |
                                                SAHPI_CAPABILITY_RESOURCE |
                                                SAHPI_CAPABILITY_SENSOR,
                        .ResourceSeverity = SAHPI_CRITICAL,
			.ResourceFailed = SAHPI_FALSE,
                },
                .res_info = {
                        .mib = {
                                .OidHealth = ".1.3.6.1.4.1.2.3.51.2.2.7.1.0",
                                .HealthyValue = 255,
                                .OidReset = '\0',
                                .OidPowerState = '\0',
                                .OidPowerOnOff = '\0',
				.OidUuid = ".1.3.6.1.4.1.2.3.51.2.2.21.1.1.4.0",
				.OidResourceWidth = '\0',
                        },
			.cur_state = 0,
			.prev_state = 0,
                        .event_array = {
                                {},
                        },
                },
                .comment = "BladeCenter Chassis",
        },
        /* Virtual Management Module */
        {
                .rpt = {
                        .ResourceInfo = {
                                .ManufacturerId = IBM_MANUFACTURING_ID,
                        },
                        .ResourceEntity = {
                                .Entry[0] =
                                {
                                        .EntityType = SAHPI_ENT_SYS_MGMNT_MODULE,
					/* Must be zero for a virtual resource */
                                        .EntityLocation = 0,
                                },
                                {
                                        .EntityType = SAHPI_ENT_ROOT,
                                        .EntityLocation = 0,   
                                }
                        },
                        .ResourceCapabilities = SAHPI_CAPABILITY_CONTROL |
			                        SAHPI_CAPABILITY_EVENT_LOG |
						SAHPI_CAPABILITY_RDR |
                                                SAHPI_CAPABILITY_RESOURCE |
			                        SAHPI_CAPABILITY_SENSOR,
                        .ResourceSeverity = SAHPI_CRITICAL,
			.ResourceFailed = SAHPI_FALSE,
                },
                .res_info = {
                        .mib = {
                                .OidHealth = '\0',
                                .HealthyValue = 0,
                                .OidReset = '\0',
                                .OidPowerState = '\0',
                                .OidPowerOnOff = '\0',
				.OidUuid = '\0',
				.OidResourceWidth = '\0',
                        },
			.cur_state = SAHPI_HS_STATE_ACTIVE,
			.prev_state = SAHPI_HS_STATE_NOT_PRESENT,
                        .event_array = {
                                {},
                        },
                },
                .comment = "Virtual Management Module",
        },	
        /* Management Module */
        {
                .rpt = {
                        .ResourceInfo = {
                                .ManufacturerId = IBM_MANUFACTURING_ID,
                        },
                        .ResourceEntity = {
                                .Entry[0] =
                                {
                                        .EntityType = SAHPI_ENT_SYS_MGMNT_MODULE,
                                        .EntityLocation = SNMP_BC_HPI_LOCATION_BASE,
                                },
                                {
                                        .EntityType = BLADECENTER_SYS_MGMNT_MODULE_SLOT,
                                        .EntityLocation = SNMP_BC_HPI_LOCATION_BASE,
                                },
                                {
                                        .EntityType = SAHPI_ENT_ROOT,
                                        .EntityLocation = 0,
                                }
                        },
                        .ResourceCapabilities = SAHPI_CAPABILITY_FRU |
                                                SAHPI_CAPABILITY_INVENTORY_DATA |
			                        SAHPI_CAPABILITY_MANAGED_HOTSWAP |
                                                SAHPI_CAPABILITY_RDR |
			                        SAHPI_CAPABILITY_RESET |
                                                SAHPI_CAPABILITY_RESOURCE |
			                        SAHPI_CAPABILITY_SENSOR,
                        .ResourceSeverity = SAHPI_MAJOR,
			.ResourceFailed = SAHPI_FALSE,
                },
                .res_info = {
                        .mib = {
                                .OidHealth = '\0',
                                .HealthyValue = 0,
                                .OidReset = ".1.3.6.1.4.1.2.3.51.2.7.4.0",
                                .OidPowerState = '\0',
                                .OidPowerOnOff = '\0',
				.OidUuid = ".1.3.6.1.4.1.2.3.51.2.2.21.2.1.1.6.x",
				.OidResourceWidth = '\0',
                        },
			.cur_state = SAHPI_HS_STATE_NOT_PRESENT,
			.prev_state = SAHPI_HS_STATE_NOT_PRESENT,
                        .event_array = {
                                {
                                        .event = "0028200x", /* EN_MM_x_INSTALLED */
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_HS_STATE_INSERTION_PENDING,
					.event_auto_state = 0,
                                        .recovery_state = SAHPI_HS_STATE_NOT_PRESENT,
					.recovery_auto_state = 0,
				},
                                {
                                        .event = "0028400x", /* EN_MM_x_REMOVED */
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_HS_STATE_NOT_PRESENT,
					.event_auto_state = 0,
                                        .recovery_state = SAHPI_HS_STATE_ACTIVE,
					.recovery_auto_state = 0,
                                },
                                {},
                        },
                },
                .comment = "Management Module",
        },
        /* I/O Module */
        {
                .rpt = {
                        .ResourceInfo = {
                                .ManufacturerId = IBM_MANUFACTURING_ID,
                        },
                        .ResourceEntity = {
                                .Entry[0] =
                                {
                                        .EntityType = SAHPI_ENT_INTERCONNECT,
                                        .EntityLocation = SNMP_BC_HPI_LOCATION_BASE,
                                },
                                {
                                        .EntityType = BLADECENTER_INTERCONNECT_SLOT,
                                        .EntityLocation = SNMP_BC_HPI_LOCATION_BASE,
                                },
                                {
                                        .EntityType = SAHPI_ENT_ROOT,
                                        .EntityLocation = 0,
                                }
                        },
                        .ResourceCapabilities = SAHPI_CAPABILITY_FRU |
                                                SAHPI_CAPABILITY_INVENTORY_DATA |
						SAHPI_CAPABILITY_MANAGED_HOTSWAP |
			                        SAHPI_CAPABILITY_POWER |
                                                SAHPI_CAPABILITY_RDR |
			                        SAHPI_CAPABILITY_RESET |
                                                SAHPI_CAPABILITY_RESOURCE |
                                                SAHPI_CAPABILITY_SENSOR,
			.HotSwapCapabilities = SAHPI_HS_CAPABILITY_AUTOEXTRACT_READ_ONLY,
                        .ResourceSeverity = SAHPI_MAJOR,
			.ResourceFailed = SAHPI_FALSE,
                },
                .res_info = {
                        .mib = {
				
				/*				
                                .OidPowerState = ".1.3.6.1.4.1.2.3.51.2.22.3.1.1.1.7.x",
                                .OidPowerOnOff = ".1.3.6.1.4.1.2.3.51.2.22.3.1.1.1.7.x",
				 */			
                                .OidHealth = '\0',
                                .HealthyValue = 0,
                                .OidReset = ".1.3.6.1.4.1.2.3.51.2.22.3.1.7.1.8.x",
                                .OidPowerState = ".1.3.6.1.4.1.2.3.51.2.22.3.2.1.1.1.1.4.x", /* smCurrentIPInfoPowerState */
                                .OidPowerOnOff = ".1.3.6.1.4.1.2.3.51.2.22.3.1.7.1.7.x",     /* switchModulePowerOnOff */
				.OidUuid = ".1.3.6.1.4.1.2.3.51.2.2.21.6.1.1.8.x",
				.OidResourceWidth = '\0',
                        },
 			.cur_state = SAHPI_HS_STATE_NOT_PRESENT,
			.prev_state = SAHPI_HS_STATE_NOT_PRESENT,
			.event_array = {
                                {
                                        .event = "0EA0200x", /* EN_SWITCH_x_INSTALLED */
					.event_res_failure = SAHPI_FALSE,
 					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_HS_STATE_INACTIVE,
 					.event_auto_state = 0,
                                        .recovery_state = 0,
					.recovery_auto_state = 0,
				},
                                {
                                        .event = "0EA0800x", /* EN_SWITCH_x_POWERED_ON */
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_HS_STATE_ACTIVE,
 					.event_auto_state = SAHPI_HS_STATE_INSERTION_PENDING,
                                        .recovery_state = 0,
					.recovery_auto_state = 0,
                                },
                                {
                                        .event = "0EA0600x", /* EN_SWITCH_x_POWERED_OFF */
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_HS_STATE_INACTIVE,
 					.event_auto_state = SAHPI_HS_STATE_EXTRACTION_PENDING,
                                        .recovery_state = 0,
					.recovery_auto_state = 0,
				},
                                {
                                        .event = "0EA0400x", /* EN_SWITCH_x_REMOVED */
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_HS_STATE_NOT_PRESENT,
  					.event_auto_state = 0,
                                        .recovery_state = 0,
 					.recovery_auto_state = 0,
				},
                                {},
                        },
                },
                .comment = "I/0 Module",
        },
        /* Blade */
        {
                .rpt = {
                        .ResourceInfo = {
                                .ManufacturerId = IBM_MANUFACTURING_ID,
                        },
                        .ResourceEntity = {
                                .Entry[0] =
                                {
                                        .EntityType = SAHPI_ENT_SBC_BLADE,
                                        .EntityLocation = SNMP_BC_HPI_LOCATION_BASE,
                                },
                                {
                                        .EntityType = SAHPI_ENT_PHYSICAL_SLOT,
                                        .EntityLocation = SNMP_BC_HPI_LOCATION_BASE,
                                },
                                {
                                        .EntityType = SAHPI_ENT_ROOT,
                                        .EntityLocation = 0,
                                }
                        },
                        .ResourceCapabilities = SAHPI_CAPABILITY_CONTROL |
                                                SAHPI_CAPABILITY_FRU |
                                                SAHPI_CAPABILITY_INVENTORY_DATA |
			                        SAHPI_CAPABILITY_MANAGED_HOTSWAP |
			                        SAHPI_CAPABILITY_POWER |
                                                SAHPI_CAPABILITY_RDR |
			                        SAHPI_CAPABILITY_RESET |
                                                SAHPI_CAPABILITY_RESOURCE |
                                                SAHPI_CAPABILITY_SENSOR,
			.HotSwapCapabilities = SAHPI_HS_CAPABILITY_AUTOEXTRACT_READ_ONLY,
                        .ResourceSeverity = SAHPI_MAJOR,
			.ResourceFailed = SAHPI_FALSE,
                },
                .res_info = {
                        .mib = {
                                .OidHealth = ".1.3.6.1.4.1.2.3.51.2.22.1.5.1.1.5.x",
                                .HealthyValue = 1,
                                .OidReset = ".1.3.6.1.4.1.2.3.51.2.22.1.6.1.1.8.x",
                                .OidPowerState = ".1.3.6.1.4.1.2.3.51.2.22.1.6.1.1.4.x",
                                .OidPowerOnOff = ".1.3.6.1.4.1.2.3.51.2.22.1.6.1.1.7.x",
				.OidUuid = ".1.3.6.1.4.1.2.3.51.2.2.21.4.1.1.8.x",
				.OidResourceWidth = ".1.3.6.1.4.1.2.3.51.2.22.1.5.1.1.15.x",
                        },
  			.cur_state = SAHPI_HS_STATE_NOT_PRESENT,
			.prev_state = SAHPI_HS_STATE_NOT_PRESENT,
			.event_array = {
                                {
                                        .event = "0E00200x", /* EN_BLADE_x_INSTALLED */
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_HS_STATE_INACTIVE,
 					.event_auto_state = 0,
                                        .recovery_state = 0,
					.recovery_auto_state = 0,
                                },
                                {
                                        .event = "1C000001", /* EN_BLADE_PWR_DWN */
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_HS_STATE_INACTIVE,
 					.event_auto_state = SAHPI_HS_STATE_EXTRACTION_PENDING,
                                        .recovery_state = 0,
 					.recovery_auto_state = 0,
				},
                                {
                                        .event = "1C000002",/* EN_BLADE_PWR_UP */
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_HS_STATE_ACTIVE,
 					.event_auto_state = SAHPI_HS_STATE_INSERTION_PENDING,
                                        .recovery_state = 0,
					.recovery_auto_state = 0,
                                },
                                {
                                        .event = "06026080", /* EN_BLADE_PWR_DN_FAN_FAIL */
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_HS_STATE_INACTIVE,
 					.event_auto_state = SAHPI_HS_STATE_EXTRACTION_PENDING,
                                        .recovery_state = SAHPI_HS_STATE_ACTIVE,
					.recovery_auto_state = SAHPI_HS_STATE_INSERTION_PENDING,
                                },
                                {
                                        .event = "0821C080", /* EN_BLADE_PWR_DN_PM_TEMP */
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_HS_STATE_INACTIVE,
 					.event_auto_state = SAHPI_HS_STATE_EXTRACTION_PENDING,
                                        .recovery_state = SAHPI_HS_STATE_ACTIVE,
 					.recovery_auto_state = SAHPI_HS_STATE_INSERTION_PENDING,
				},
                                {
                                        .event = "0E00400x", /* EN_BLADE_x_REMOVED */
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_HS_STATE_NOT_PRESENT,
  					.event_auto_state = 0,
                                        .recovery_state = 0,
					.recovery_auto_state = 0,
				},
                                {},
                        },
                },
                .comment = "Blade",
		.OidResourceTag = ".1.3.6.1.4.1.2.3.51.2.2.8.2.1.1.6.x"
        },
        /* Blade Expansion Module (BEM) */
        {
                .rpt = {
                        .ResourceInfo = {
                                .ManufacturerId = IBM_MANUFACTURING_ID,
                        },
                        .ResourceEntity = {
                                .Entry[0] =
                                {
                                        .EntityType = SAHPI_ENT_SYS_EXPANSION_BOARD,
                                        .EntityLocation = SNMP_BC_HPI_LOCATION_BASE,
                                },
                                {
                                        .EntityType = SAHPI_ENT_SBC_BLADE,
                                        .EntityLocation = SNMP_BC_HPI_LOCATION_BASE,
                                },
                                {
                                        .EntityType = SAHPI_ENT_PHYSICAL_SLOT,
                                        .EntityLocation = SNMP_BC_HPI_LOCATION_BASE,
                                },
                                {
                                        .EntityType = SAHPI_ENT_ROOT,
                                        .EntityLocation = 0,
                                }
                        },
                        .ResourceCapabilities = SAHPI_CAPABILITY_RDR |
                                                SAHPI_CAPABILITY_RESOURCE |
			                        SAHPI_CAPABILITY_SENSOR,
                        .ResourceSeverity = SAHPI_MAJOR,
			.ResourceFailed = SAHPI_FALSE,
                },
                .res_info = {
                        .mib = {
                                .OidHealth = '\0',
                                .HealthyValue = 0,
                                .OidReset = '\0',
                                .OidPowerState = '\0',
                                .OidPowerOnOff = '\0',
				.OidUuid = '\0',
				.OidResourceWidth = '\0',
                        },
  			.cur_state = 0,
			.prev_state = 0,
                        .event_array = {
                                {},
                        },
                },
                .comment = "Blade Expansion Module",
        },
        /* Media Tray */
        {
                .rpt = {
                        .ResourceInfo = {
                                .ManufacturerId = IBM_MANUFACTURING_ID,
                        },
                        .ResourceEntity = {
                                .Entry[0] =
                                {
                                        .EntityType = SAHPI_ENT_PERIPHERAL_BAY,
                                        .EntityLocation = SNMP_BC_HPI_LOCATION_BASE,
                                },
                                {
                                        .EntityType = BLADECENTER_PERIPHERAL_BAY_SLOT,
                                        .EntityLocation = SNMP_BC_HPI_LOCATION_BASE,
                                },
                                {
                                        .EntityType = SAHPI_ENT_ROOT,
                                        .EntityLocation = 0,
                                }
                        },
                        .ResourceCapabilities = SAHPI_CAPABILITY_FRU |
			                        SAHPI_CAPABILITY_INVENTORY_DATA |
                                                SAHPI_CAPABILITY_RDR |
                                                SAHPI_CAPABILITY_RESOURCE |
                                                SAHPI_CAPABILITY_SENSOR,
                        .ResourceSeverity = SAHPI_MAJOR,
			.ResourceFailed = SAHPI_FALSE,
                },
                .res_info = {
                        .mib = {
                                .OidHealth = '\0',
                                .HealthyValue = 0,
                                .OidReset = '\0',
                                .OidPowerState = '\0',
                                .OidPowerOnOff = '\0',
				.OidUuid = ".1.3.6.1.4.1.2.3.51.2.2.21.9.8.0",
				.OidResourceWidth = '\0',
                        },
  			.cur_state = SAHPI_HS_STATE_NOT_PRESENT,
			.prev_state = SAHPI_HS_STATE_NOT_PRESENT,
                        .event_array = {
                                {
                                        .event = "06A1E001", /* EN_MEDIA_TRAY_REMOVED */
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_HS_STATE_NOT_PRESENT,
					.event_auto_state = 0,
                                        .recovery_state = SAHPI_HS_STATE_ACTIVE,
					.recovery_auto_state = 0,
                                },
                                {},
                        },
                },
                .comment = "Media Tray",
        },
        /* Blower Module */
        {
                .rpt = {
                        .ResourceInfo = {
                                .ManufacturerId = IBM_MANUFACTURING_ID,
                        },
                        .ResourceEntity = {
                                .Entry[0] =
                                {
                                        .EntityType = SAHPI_ENT_FAN,
                                        .EntityLocation = SNMP_BC_HPI_LOCATION_BASE,
                                },
                                {
                                        .EntityType = BLADECENTER_BLOWER_SLOT,
                                        .EntityLocation = SNMP_BC_HPI_LOCATION_BASE,
                                },
                                {
                                        .EntityType = SAHPI_ENT_ROOT,
                                        .EntityLocation = 0,
                                }
                        },
                        .ResourceCapabilities = SAHPI_CAPABILITY_FRU |
                                                SAHPI_CAPABILITY_RDR |
                                                SAHPI_CAPABILITY_RESOURCE |
                                                SAHPI_CAPABILITY_SENSOR,
                        .ResourceSeverity = SAHPI_MAJOR,
			.ResourceFailed = SAHPI_FALSE,
                 },
                .res_info = {
                        .mib = {
                                .OidHealth = '\0',
                                .HealthyValue = 0,
                                .OidReset = '\0',
                                .OidPowerState = '\0',
                                .OidPowerOnOff = '\0',
				.OidUuid = '\0',
				.OidResourceWidth = '\0',
                        },
  			.cur_state = SAHPI_HS_STATE_NOT_PRESENT,
			.prev_state = SAHPI_HS_STATE_NOT_PRESENT,
                        .event_array = {
				{
                                        .event = "0A02600x", /* EN_FAULT_FANx */
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_HS_STATE_NOT_PRESENT,
 					.event_auto_state = 0,
					.recovery_state = SAHPI_HS_STATE_ACTIVE,
 					.recovery_auto_state = 0,
				},
				{},
                        },
                },
                .comment = "Blower Module",
        },
        /* Power Module */
        {
                .rpt = {
                        .ResourceInfo = {
                                .ManufacturerId = IBM_MANUFACTURING_ID,
                        },
                        .ResourceEntity = {
                                .Entry[0] =
                                {
                                        .EntityType = SAHPI_ENT_POWER_SUPPLY,
                                        .EntityLocation = SNMP_BC_HPI_LOCATION_BASE,
                                },
                                {
                                        .EntityType = BLADECENTER_POWER_SUPPLY_SLOT,
                                        .EntityLocation = SNMP_BC_HPI_LOCATION_BASE,
                                },
                                {
                                        .EntityType = SAHPI_ENT_ROOT,
                                        .EntityLocation = 0,
                                }
                        },
                        .ResourceCapabilities = SAHPI_CAPABILITY_FRU |
			                        SAHPI_CAPABILITY_INVENTORY_DATA |
                                                SAHPI_CAPABILITY_RDR |
                                                SAHPI_CAPABILITY_RESOURCE |
                                                SAHPI_CAPABILITY_SENSOR,
                        .ResourceSeverity = SAHPI_MAJOR,
			.ResourceFailed = SAHPI_FALSE,
                 },
                .res_info = {
                        .mib = {
                                .OidHealth = '\0',
                                .HealthyValue = 0,
                                .OidReset = '\0',
                                .OidPowerState = '\0',
                                .OidPowerOnOff = '\0',
				.OidUuid = ".1.3.6.1.4.1.2.3.51.2.2.21.8.1.1.8.x",
				.OidResourceWidth = '\0',
                        },
  			.cur_state = SAHPI_HS_STATE_NOT_PRESENT,
			.prev_state = SAHPI_HS_STATE_NOT_PRESENT,
                        .event_array = {
                                {
                                        .event = "0821600x", /* EN_PSx_INSTALLED */
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_HS_STATE_ACTIVE,
					.event_auto_state = 0,
                                        .recovery_state = SAHPI_HS_STATE_NOT_PRESENT,
					.recovery_auto_state = 0,
                                },
                                {
                                        .event = "0821E00x", /* EN_FAULT_PSx_REMOVED */
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_HS_STATE_NOT_PRESENT,
					.event_auto_state = 0,
                                        .recovery_state = SAHPI_HS_STATE_ACTIVE,
 					.recovery_auto_state = 0,
				},
                                {},
                        },
                },
                .comment = "Power Module",
        },
        /* Slot */
        {
                .rpt = {
                        .ResourceInfo = {
                                .ManufacturerId = IBM_MANUFACTURING_ID,
                        },
                        .ResourceEntity = {
                                .Entry[0] =
                                {
					/* dummy setting - set during discovery */
                                        .EntityType = SAHPI_ENT_CHASSIS_SPECIFIC,
                                        .EntityLocation = SNMP_BC_HPI_LOCATION_BASE,
                                },
                                {
                                        .EntityType = SAHPI_ENT_ROOT,
                                        .EntityLocation = 0,
                                }
                        },
                         
                        .ResourceCapabilities = SAHPI_CAPABILITY_RESOURCE |
						SAHPI_CAPABILITY_RDR |
                                                SAHPI_CAPABILITY_SENSOR,
                        .ResourceSeverity = SAHPI_MAJOR,
			.ResourceFailed = SAHPI_FALSE,
                 },
                .res_info = {
                        .mib = {
                                .OidHealth = '\0',
                                .HealthyValue = 0,
                                .OidReset = '\0',
                                .OidPowerState = '\0',
                                .OidPowerOnOff = '\0',
				.OidUuid = '\0',
				.OidResourceWidth = '\0',
                        },
  			.cur_state = SAHPI_HS_STATE_ACTIVE,
			.prev_state = SAHPI_HS_STATE_ACTIVE,
                        .event_array = {
                                {},
                        },
                },
                .comment = "Slot",
        },

        {} /* Terminate array with a null element */
};

/*************************************************************************
 *                      Sensor Definitions
 *************************************************************************/

/*************************************************************************
 * WARNING  -   WARNING  - WARNING  -  WARNING
 * Most of the .sensor.num are assigned sequentially. 
 * There are 8 hardcoded, specifically assigned, sensor numbers:
 * 
 *   SAHPI_DEFAGSENS_OPER			(SaHpiSensorNumT)0x00000100 
 *   BLADECENTER_SENSOR_NUM_MGMNT_REDUNDANCY	(SaHpiSensorNumT) 0x1001
 *   BLADECENTER_SENSOR_NUM_MGMNT_ACTIVE  	(SaHpiSensorNumT) 0x1002
 *   BLADECENTER_SENSOR_NUM_MGMNT_STANDBY 	(SaHpiSensorNumT) 0x1003
 *   BLADECENTER_SENSOR_NUM_SLOT_STATE  	(SaHpiSensorNumT) 0x1010
 *   BLADECENTER_SENSOR_NUM_MAX_POWER  		(SaHpiSensorNumT) 0x1012
 *   BLADECENTER_SENSOR_NUM_ASSIGNED_POWER  	(SaHpiSensorNumT) 0x1011
 *   BLADECENTER_SENSOR_NUM_MIN_POWER  		(SaHpiSensorNumT) 0x1013
 *************************************************************************/

/*****************
 * Chassis Sensors
 *****************/

struct snmp_bc_sensor snmp_bc_chassis_sensors[] = {
        /* Ambient Air Temperature Sensor */
        {
		.index = 1,
                .sensor = {
                        .Num = 1,
                        .Type = SAHPI_TEMPERATURE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_DEGREES_C,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
                                        .Max = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 125,
						},
					},
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
						},
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_FALSE,
                                .ReadThold = 0,
				.WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.1.5.1.0",
				.loc_offset = 0,
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
                        .assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
                        .deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
                        .event_array = {
				{
                                        .event = "6F400000", /* EN_FAULT_CRT_AMBIENT */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UPPER_MAJOR,
                                },
				{
                                        .event = "0001D500", /* EN_PFA_HI_OVER_TEMP_AMBIENT */
 					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
                        .reading2event = {
				{
					.num = 1,
                                        .rangemap = {
						.Flags = SAHPI_SRF_MIN,
						.Min = {
							.Value = {
								.SensorFloat64 = 39.0,
							},
						},
					},
					.state = SAHPI_ES_UNSPECIFIED,
                                },
				{
					.num = 2,
                                        .rangemap = {
						.Flags = SAHPI_SRF_MAX,
						.Max = {
							.Value = {
								.SensorFloat64 = 39.0,
							},
						},
					},
					.state = SAHPI_ES_UPPER_MAJOR,
                                },
				{
					.num = 3,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorFloat64 = 39.0,
							},
						},
					},
					.state = SAHPI_ES_UNSPECIFIED,
                                },
				{},
			},
                },
                .comment = "Ambient Air Temperature Sensor",
        },
        /* I/O Module Redundancy Sensor - event-only */
        {
		.index = 2,
                .sensor = {
                        .Num = 2,
                        .Type = SAHPI_PLATFORM_ALERT,
                        .Category = SAHPI_EC_REDUNDANCY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_REDUNDANCY_LOST | SAHPI_ES_FULLY_REDUNDANT,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_FULLY_REDUNDANT,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_REDUNDANCY_LOST,
			.deassert_mask = SAHPI_ES_REDUNDANCY_LOST,
                        .event_array = {
                                {
                                        .event = "0EA16000", /* EN_SWITCH_NON_REDUNDANT */
 					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_REDUNDANCY_LOST,
                                        .recovery_state = SAHPI_ES_FULLY_REDUNDANT,
                                },
                                {},
                        },
 			.reading2event = {},
               },
                .comment = "I/O Module Redundancy Sensor",
        },
        /* Power Module Redundancy Sensor - event-only */
        {
		.index = 3,
                .sensor = {
                        .Num = 3,
                        .Type = SAHPI_PLATFORM_ALERT,
                        .Category = SAHPI_EC_REDUNDANCY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_REDUNDANCY_LOST | SAHPI_ES_FULLY_REDUNDANT,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_FULLY_REDUNDANT,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_REDUNDANCY_LOST,
			.deassert_mask = SAHPI_ES_REDUNDANCY_LOST,
                        .event_array = {
                                {
                                        .event = "08080001", /* EN_NR_PWR_SUPPLY */
 					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_REDUNDANCY_LOST,
                                        .recovery_state = SAHPI_ES_FULLY_REDUNDANT,
                                },
                                {
                                        .event = "08081001", /* EN_NR_PWR_SUPPLY_DOM_1 */
 					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_REDUNDANCY_LOST,
                                        .recovery_state = SAHPI_ES_FULLY_REDUNDANT,
                                },
                                {
                                        .event = "08081002", /* EN_NR_PWR_SUPPLY_DOM_2 */
 					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_REDUNDANCY_LOST,
                                        .recovery_state = SAHPI_ES_FULLY_REDUNDANT,
                                },
                                {},
                        },
 			.reading2event = {},
               },
                .comment = "Power Module Redundancy Sensor",
        },
        /* Power Domain 1 Redundancy Sensor - event-only */
        {
		.index = 4,
                .sensor = {
                        .Num = 4,
                        .Type = SAHPI_PLATFORM_ALERT,
                        .Category = SAHPI_EC_REDUNDANCY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_REDUNDANCY_LOST | SAHPI_ES_FULLY_REDUNDANT,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_FULLY_REDUNDANT,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_REDUNDANCY_LOST,
			.deassert_mask = SAHPI_ES_REDUNDANCY_LOST,
                        .event_array = {
                                {
                                        .event = "08008401", /* EN_PWR_DOMAIN_1_OVER_SUBSCRIP */
 					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_REDUNDANCY_LOST,
                                        .recovery_state = SAHPI_ES_FULLY_REDUNDANT,
                                },
                                {
                                        .event = "08008401", /* EN_PWR_DOMAIN_1_OVER_SUBSCRIP_NONREC */
 					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_REDUNDANCY_LOST,
                                        .recovery_state = SAHPI_ES_FULLY_REDUNDANT,
                                },
                                {},
                        },
 			.reading2event = {},
               },
                .comment = "Power Domain 1 Redundancy Sensor",
        },
        /* Power Domain 2 Redundancy Sensor - event-only */
        {
		.index = 5,
                .sensor = {
                        .Num = 5,
                        .Type = SAHPI_PLATFORM_ALERT,
                        .Category = SAHPI_EC_REDUNDANCY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_REDUNDANCY_LOST | SAHPI_ES_FULLY_REDUNDANT,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_FULLY_REDUNDANT,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_REDUNDANCY_LOST,
			.deassert_mask = SAHPI_ES_REDUNDANCY_LOST,
                        .event_array = {
                                {
                                        .event = "08008402", /* EN_PWR_DOMAIN_2_OVER_SUBSCRIP_NONREC */
 					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_REDUNDANCY_LOST,
                                        .recovery_state = SAHPI_ES_FULLY_REDUNDANT,
                                },
                                {},
                        },
 			.reading2event = {},
               },
                .comment = "Power Domain 2 Redundancy Sensor",
        },
	/* Chassis Total Maximum Power Capability Sensor */
	{
		.index = 6,
                .sensor = {
                        .Num = BLADECENTER_SENSOR_NUM_MAX_POWER,
                        .Type = SAHPI_OTHER_UNITS_BASED_SENSOR,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = 0,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_UINT64,
                                .BaseUnits = SAHPI_SU_WATTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
				.Range = {},
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
		.sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.10.2.1.1.8.1", 
                                .threshold_oids = {},
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_FALSE,
			.assert_mask   = 0,
			.deassert_mask = 0,
			.event_array = {
                                {},
                        },
		        .reading2event = {},
                },
		.comment = "Chassis Total Maximum Power Capability Sensor",
	},
	/* Chassis Total Assigned Power Sensor */
	{
		.index = 7,
                .sensor = {
                        .Num = BLADECENTER_SENSOR_NUM_ASSIGNED_POWER,
                        .Type = SAHPI_OTHER_UNITS_BASED_SENSOR,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = 0,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_UINT64,
                                .BaseUnits = SAHPI_SU_WATTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
				.Range = {},
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_FALSE,
                                .ReadThold = 0,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
		.sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.10.2.1.1.7.1",
                                .threshold_oids = {},			
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_FALSE,
			.assert_mask   = 0,
			.deassert_mask = 0,
			.event_array = {
                                {},
                        },
		        .reading2event = {},
                },
		.comment = "Chassis Total Assigned Power Sensor",
	},
	/* Chassis Total Minumum Power Capability Sensor */
	{
		.index = 8,
                .sensor = {
                        .Num = BLADECENTER_SENSOR_NUM_MIN_POWER,
                        .Type = SAHPI_OTHER_UNITS_BASED_SENSOR,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = 0,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_UINT64,
                                .BaseUnits = SAHPI_SU_WATTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
				.Range = {},
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_FALSE,
                                .ReadThold = 0,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
		.sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.10.2.1.1.9.1",
                                .threshold_oids = {},
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_FALSE,
			.assert_mask   = 0,
			.deassert_mask = 0,
			.event_array = {
                                {},
                        },
		        .reading2event = {},
                },
		.comment = "Chassis Total Minumum Power Capability Sensor",
	},

        {} /* Terminate array with a null element */
};

#define SNMP_BC_MAX_COMMON_CHASSIS_SENSORS 8

struct snmp_bc_sensor snmp_bc_chassis_sensors_bct[] = {
        /* Chassis Filter Sensor - event only */
        {
		.index = SNMP_BC_MAX_COMMON_CHASSIS_SENSORS + 1,
                .sensor = {
                        .Num = SNMP_BC_MAX_COMMON_CHASSIS_SENSORS + 1,
                        .Type = SAHPI_TEMPERATURE,
                        .Category = SAHPI_EC_SEVERITY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_OK | SAHPI_ES_MINOR_FROM_OK |
			          SAHPI_ES_INFORMATIONAL |
			          SAHPI_ES_MAJOR_FROM_LESS | SAHPI_ES_CRITICAL,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_OK,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_OK | SAHPI_ES_MINOR_FROM_OK |
			                 SAHPI_ES_INFORMATIONAL |
			                 SAHPI_ES_MAJOR_FROM_LESS | SAHPI_ES_CRITICAL,
			.deassert_mask = SAHPI_ES_OK | SAHPI_ES_MINOR_FROM_OK |
			                 SAHPI_ES_INFORMATIONAL |
			                 SAHPI_ES_MAJOR_FROM_LESS | SAHPI_ES_CRITICAL,
                        .event_array = {
                                {
                                        .event = "6F100000", /* EN_FAULT_CRT_FILTER */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_CRITICAL,
                                        .recovery_state = SAHPI_ES_MAJOR_FROM_LESS,
                                },
                                {
                                        .event = "6F200000", /* EN_FAULT_MJR_FILTER */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_MAJOR_FROM_LESS,
                                        .recovery_state = SAHPI_ES_MINOR_FROM_OK,
                                },
                                {
                                        .event = "6F300000", /* EN_FAULT_MNR_FILTER */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_MINOR_FROM_OK,
                                        .recovery_state = SAHPI_ES_OK,
                                },
                                {
                                        .event = "6F500000", /* EN_FAULT_MNR_FILTER_SERVICE */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_INFORMATIONAL,
                                        .recovery_state = SAHPI_ES_OK,
                                },
                        },
   			.reading2event = {},
               },
                .comment = "Chassis Filter Sensor",
        },

       {} /* Terminate array with a null element */
};

/***********************************
 * Virtual Management Module Sensors
 ***********************************/

struct snmp_bc_sensor snmp_bc_virtual_mgmnt_sensors[] = {
        /* MM Air Temperature */
        {
		.index = 1,
                .sensor = {
                        .Num = 1,
                        .Type = SAHPI_TEMPERATURE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_UPPER_MAJOR,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_DEGREES_C,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
                                        .Max = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 125,
						},
					},
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
						},
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_FALSE,
                                .ReadThold = 0,
				.WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.1.1.2.0",
				.loc_offset = 0,
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
                        .assert_mask   = SAHPI_ES_UPPER_MAJOR,
                        .deassert_mask = SAHPI_ES_UPPER_MAJOR,
                        .event_array = {
                                {
                                        .event = "0001D400", /* EN_PFA_HI_OVER_TEMP_SP_CARD */
 					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
                        .reading2event = {
				{
					.num = 1,
                                        .rangemap = {
						.Flags = SAHPI_SRF_MIN,
						.Min = {
							.Value = {
								.SensorFloat64 = 60.0,
							},
						},
					},
					.state = SAHPI_ES_UNSPECIFIED,
                                },
				{
					.num = 2,
                                        .rangemap = {
						.Flags = SAHPI_SRF_MAX,
						.Max = {
							.Value = {
								.SensorFloat64 = 60.0,
							},
						},
					},
					.state = SAHPI_ES_UPPER_MAJOR,
                                },
				{
					.num = 3,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorFloat64 = 60.0,
							},
						},
					},
					.state = SAHPI_ES_UNSPECIFIED,
                                },
				{},
			},
                },
                .comment = "MM Air Temperature Sensor",
        },
        /* System 1.8 Volt Sensor */
        {
		.index = 2,
                .sensor = {
                        .Num = 2,
                        .Type = SAHPI_VOLTAGE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
			.Events = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_VOLTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
				.Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
                                        .Max = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 4.4,
						},
                                        },
                                        .Nominal = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 1.8,
						},
                                        },
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
						},
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_TRUE,
                                .ReadThold = SAHPI_STM_LOW_CRIT | SAHPI_STM_UP_CRIT |
                                             SAHPI_STM_LOW_HYSTERESIS | SAHPI_STM_UP_HYSTERESIS,
				.WriteThold = 0,
                         },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.2.1.8.0",
				.loc_offset = 0,
                                .threshold_oids = {
					.LowCritical = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.10.6",
					.UpCritical  = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.6.6",
					.TotalPosThdHysteresis = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.7.6",
					.TotalNegThdHysteresis = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.11.6",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
			.deassert_mask = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
                        .event_array = {
                                {
                                        .event = "0807B401", /* EN_I2C_HI_FAULT_1_8V */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {
                                        .event = "0807B801", /* EN_I2C_LO_FAULT_1_8V */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_LOWER_CRIT,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
			.reading2event = {},
                },
                .comment = "System 1.8 Volt Sensor",
        },
        /* System 2.5 Volt Sensor */
        {
		.index = 3,
                .sensor = {
                        .Num = 3,
                        .Type = SAHPI_VOLTAGE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_VOLTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
                                        .Max = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 4.4,
						},
                                        },
                                        .Nominal = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 2.5,
                                                },
                                        },
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_TRUE,
                                .ReadThold = SAHPI_STM_LOW_CRIT | SAHPI_STM_UP_CRIT |
				             SAHPI_STM_LOW_HYSTERESIS | SAHPI_STM_UP_HYSTERESIS,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
		.sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.2.1.6.0",
 				.loc_offset = 0,
				.threshold_oids = {
					.LowCritical = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.10.5",
					.UpCritical  = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.6.5",
					.TotalPosThdHysteresis  = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.7.5",
					.TotalNegThdHysteresis = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.11.5",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
			.deassert_mask = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
                        .event_array = {
                                {
                                        .event = "08031481", /* EN_I2C_HI_FAULT_2_5V */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {
                                        .event = "08031881", /* EN_I2C_LO_FAULT_2_5V */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_LOWER_CRIT,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
			.reading2event = {},
                },
                .comment = "System 2.5 Volt Sensor",
        },
        /* System 3.3 Volt Sensor */
	{
		.index = 4,
                .sensor = {
                        .Num = 4,
                        .Type = SAHPI_VOLTAGE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_VOLTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
				.Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
                                        .Max = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 3.6,
                                                },
                                        },
                                        .Nominal = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 3.3,
                                                },
                                        },
                                        .Min = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_TRUE,
                                .ReadThold = SAHPI_STM_LOW_CRIT | SAHPI_STM_UP_CRIT |
				             SAHPI_STM_LOW_HYSTERESIS | SAHPI_STM_UP_HYSTERESIS,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
		.sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.2.1.2.0",
				.loc_offset = 0,
                                .threshold_oids = {
					.LowCritical = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.10.2",
					.UpCritical  = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.6.2",
					.TotalPosThdHysteresis  = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.7.2",
					.TotalNegThdHysteresis = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.11.2",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
			.deassert_mask = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
			.event_array = {
                                {
                                        .event = "08033481", /* EN_I2C_HI_FAULT_3_35V */
 					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
				/* FIXME: Need right number from MM */
				{
                                        .event = "FFFFFFF0", /* EN_I2C_LO_FAULT_3_35V */
 					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_LOWER_CRIT,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
		        .reading2event = {},
                },
		.comment = "System 3.3 Volt Sensor",
	},
        /* System 5 Volt Sensor */
        {
		.index = 5,
                .sensor = {
                        .Num = 5,
                        .Type = SAHPI_VOLTAGE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
			.DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_VOLTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
				.Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
                                        .Max = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 6.7,
						},
                                        },
                                        .Nominal = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 5,
						},
                                        },
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
				},
			},
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_TRUE,
                                .ReadThold = SAHPI_STM_LOW_CRIT | SAHPI_STM_UP_CRIT |
                                             SAHPI_STM_LOW_HYSTERESIS | SAHPI_STM_UP_HYSTERESIS,
                                .WriteThold = 0,
                         },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.2.1.1.0",
 				.loc_offset = 0,
				.threshold_oids = {
					.LowCritical = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.10.1",
					.UpCritical  = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.6.1",
					.TotalPosThdHysteresis  = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.7.1",
					.TotalNegThdHysteresis = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.11.1",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
                        .assert_mask   = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
			.deassert_mask = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
                        .event_array = {
				/* FIXME:: Need right number from MM */
                                {
                                        .event = "FFFFFFF1", /* EN_I2C_HI_FAULT_PLANAR_5V */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {
                                        .event = "06035801", /* EN_I2C_LO_FAULT_PLANAR_5V */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_LOWER_CRIT,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
			.reading2event = {},
                },
                .comment = "System 5 Volt Sensor",
        },
        /* System -5 Volt Sensor */
        {
		.index = 6,
                .sensor = {
                        .Num = 6,
                        .Type = SAHPI_VOLTAGE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_VOLTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
                                        .Max = {
  						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                        .Nominal = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = -5,
                                                },
                                        },
                                        .Min = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = -6.7,
                                                },
                                        },
                                },
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_TRUE,
                                .ReadThold = SAHPI_STM_LOW_CRIT | SAHPI_STM_UP_CRIT |
                                             SAHPI_STM_LOW_HYSTERESIS | SAHPI_STM_UP_HYSTERESIS,
                                .WriteThold = 0,
                         },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.2.1.5.0",
				.loc_offset = 0,
                                .threshold_oids = {
					.LowCritical = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.10.4",
					.UpCritical  = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.6.4",
					.TotalPosThdHysteresis  = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.7.4",
					.TotalNegThdHysteresis = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.11.4",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
			.deassert_mask = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
                        .event_array = {
                                {
                                        .event = "0803D501", /* EN_I2C_HI_FAULT_N5V */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {
					.event = "0803D801", /* EN_I2C_LO_FAULT_N5V */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_LOWER_CRIT,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
			.reading2event = {},
                },
                .comment = "System -5 Volt Sensor",
        },
        /* System 12 Volt Sensor */
        {
		.index = 7,
                .sensor = {
                        .Num = 7,
                        .Type = SAHPI_VOLTAGE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_VOLTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
                                        .Max = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 16,
                                                },
                                        },
                                        .Nominal = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 12,
                                                },
                                        },
                                        .Min = {
 						.IsSupported = SAHPI_TRUE,
						.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
						},
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_TRUE,
                                .ReadThold = SAHPI_STM_LOW_CRIT | SAHPI_STM_UP_CRIT |
                                             SAHPI_STM_LOW_HYSTERESIS | SAHPI_STM_UP_HYSTERESIS,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.2.1.3.0",
				.loc_offset = 0,
                                .threshold_oids = {
					.LowCritical = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.10.3",
					.UpCritical  = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.6.3",
					.TotalPosThdHysteresis  = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.7.3",
					.TotalNegThdHysteresis = ".1.3.6.1.4.1.2.3.51.2.2.20.2.1.1.11.3",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
			.deassert_mask = SAHPI_ES_LOWER_CRIT | SAHPI_ES_UPPER_CRIT,
                        .event_array = {
                                {
                                        .event = "06037503", /* EN_I2C_HI_FAULT_12V_PLANAR */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {
                                        .event = "06037801", /* EN_I2C_LO_FAULT_12V_PLANAR */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_LOWER_CRIT,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
			.reading2event = {},
                },
                .comment = "System 12 Volt Sensor",
        },
	/* System Management Bus Operational State Sensor - event only */
        {
		.index = 8,
                .sensor = {
                        .Num = 8,
                        .Type = SAHPI_OPERATIONAL,
                        .Category = SAHPI_EC_AVAILABILITY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
			.Events = SAHPI_ES_RUNNING | SAHPI_ES_DEGRADED | SAHPI_ES_OFF_LINE,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_RUNNING,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_DEGRADED | SAHPI_ES_OFF_LINE,
			.deassert_mask = SAHPI_ES_DEGRADED | SAHPI_ES_OFF_LINE,
                        .event_array = {
                                {
                                        .event = "00020000", /* EN_I2C_BUS_0_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020001", /* EN_I2C_BUS_1_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020002", /* EN_I2C_BUS_2_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020003", /* EN_I2C_BUS_3_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020004", /* EN_I2C_BUS_4_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020005", /* EN_I2C_BUS_5_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020006", /* EN_I2C_BUS_6_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020007", /* EN_I2C_BUS_7_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020008", /* EN_I2C_BUS_8_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020009", /* EN_I2C_BUS_9_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0002000A", /* EN_I2C_BUS_10_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0002000B", /* EN_I2C_BUS_11_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0002000C", /* EN_I2C_BUS_12_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0002000D", /* EN_I2C_BUS_13_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0002000E", /* EN_I2C_BUS_14_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0002000F", /* EN_I2C_BUS_15_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020010", /* EN_I2C_BUS_16_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020011", /* EN_I2C_BUS_17_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020012", /* EN_I2C_BUS_18_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020013", /* EN_I2C_BUS_19_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020014", /* EN_I2C_BUS_20_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020015", /* EN_I2C_BUS_21_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020016", /* EN_I2C_BUS_22_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020017", /* EN_I2C_BUS_23_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020018", /* EN_I2C_BUS_24_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00020019", /* EN_I2C_BUS_25_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0002001A", /* EN_I2C_BUS_26_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00216015", /* EN_SP_CTRL_OFFLINE */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00216016", /* EN_SP_CTRL_UNAVAILABLE */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00022014", /* EN_STCONN_FAIL_MIDPLANE */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00216014", /* EN_SP_CTRL_DEGRADED */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00216013", /* EN_SP_SENSOR_DEGRADED */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {},
                        },
   			.reading2event = {},
                },
                .comment = "System Management Bus Operational State Sensor",
        },
        /* MM Redundancy Sensor - event-only */
        {
		.index = 9,
                .sensor = {
                        .Num = BLADECENTER_SENSOR_NUM_MGMNT_REDUNDANCY,
                        .Type = SAHPI_OPERATIONAL,
                        .Category = SAHPI_EC_REDUNDANCY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_FULLY_REDUNDANT | 
			          SAHPI_ES_NON_REDUNDANT_SUFFICIENT_RESOURCES,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_NON_REDUNDANT_SUFFICIENT_RESOURCES | 
					 SAHPI_ES_FULLY_REDUNDANT,
			.deassert_mask = SAHPI_ES_NON_REDUNDANT_SUFFICIENT_RESOURCES | 
					 SAHPI_ES_FULLY_REDUNDANT,
                        .event_array = {
                                {
                                        .event = "00284000", /* EN_MM_NON_REDUNDANT */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_NON_REDUNDANT_SUFFICIENT_RESOURCES,
                                        .recovery_state = SAHPI_ES_FULLY_REDUNDANT,
                                },
                                {},
                        },
			.reading2event = {},
                },
                .comment = "MM Redundancy Sensor",
        },
        /* Active MM Sensor */
        {
		.index = 10,
                .sensor = {
                        .Num = BLADECENTER_SENSOR_NUM_MGMNT_ACTIVE,
                        .Type = SAHPI_ENTITY_PRESENCE,
                        .Category = SAHPI_EC_PRESENCE,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY |
				     SAHPI_SEC_READ_ONLY_MASKS |
				     SAHPI_SEC_PER_EVENT,
                        .Events = SAHPI_ES_PRESENT | SAHPI_ES_ABSENT, 
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_UINT64,
                                .BaseUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {} 
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.4.34.0",
				.loc_offset = 0,
                        },
                        .cur_state = SAHPI_ES_PRESENT,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_FALSE,
                        .assert_mask   = 0,
                        .deassert_mask = 0,
                        .event_array = {
                                {},
			},
                        .reading2event = {},
                },
                .comment = "Active MM Sensor",
        },	
        /* Standby MM Sensor */
        {
		.index = 11,
                .sensor = {
                        .Num = BLADECENTER_SENSOR_NUM_MGMNT_STANDBY,
                        .Type = SAHPI_ENTITY_PRESENCE,
                        .Category = SAHPI_EC_PRESENCE,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY |
				     SAHPI_SEC_READ_ONLY_MASKS |
				     SAHPI_SEC_PER_EVENT,
                        .Events = SAHPI_ES_PRESENT | SAHPI_ES_ABSENT, 
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_UINT64,
                                .BaseUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {} 
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.4.34.0",
				.loc_offset = 0,
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_FALSE,
                        .assert_mask   = 0,
                        .deassert_mask = 0,
                        .event_array = {
                                {},
			},
                        .reading2event = {},
                },
                .comment = "Standby MM Sensor",
        },
	/* Midplane Maximum Power Capability Sensor */
	{
		.index = 12,
                .sensor = {
                        .Num = BLADECENTER_SENSOR_NUM_MAX_POWER,
                        .Type = SAHPI_OTHER_UNITS_BASED_SENSOR,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = 0,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_UINT64,
                                .BaseUnits = SAHPI_SU_WATTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
				.Range = {},
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
		.sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.10.2.1.1.8.1", 
                                .threshold_oids = {},
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_FALSE,
			.assert_mask   = 0,
			.deassert_mask = 0,
			.event_array = {
                                {},
                        },
		        .reading2event = {},
                },
		.comment = "Midplane Maximum Power Capability Sensor",
	},
	/* Midplane Assigned Power Sensor */
	{
		.index = 13,
                .sensor = {
                        .Num = BLADECENTER_SENSOR_NUM_ASSIGNED_POWER,
                        .Type = SAHPI_OTHER_UNITS_BASED_SENSOR,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = 0,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_UINT64,
                                .BaseUnits = SAHPI_SU_WATTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
				.Range = {
                                        .Flags = 0x00,
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_FALSE,
                                .ReadThold = 0,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
		.sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.10.2.1.1.7.1",
                                .threshold_oids = {},			
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_FALSE,
			.assert_mask   = 0x00,
			.deassert_mask = 0x00,
			.event_array = {
                                {},
                        },
		        .reading2event = {},
                },
		.comment = "Midplane Assigned Power Sensor",
	},
	/* Midplane Minumum Power Capability Sensor */
	{
		.index = 14,
                .sensor = {
                        .Num = BLADECENTER_SENSOR_NUM_MIN_POWER,
                        .Type = SAHPI_OTHER_UNITS_BASED_SENSOR,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = 0,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_UINT64,
                                .BaseUnits = SAHPI_SU_WATTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
				.Range = {},
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_FALSE,
                                .ReadThold = 0,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
		.sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.10.2.1.1.9.1",
                                .threshold_oids = {},
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_FALSE,
			.assert_mask   = 0,
			.deassert_mask = 0,
			.event_array = {
                                {},
                        },
		        .reading2event = {},
                },
		.comment = "Midplane Minumum Power Capability Sensor",
	},

        {} /* Terminate array with a null element */
};

/***************************
 * Management Module Sensors
 ***************************/

struct snmp_bc_sensor snmp_bc_mgmnt_sensors[] = {

        {} /* Terminate array with a null element */
};

/***************
 * Blade Sensors
 ***************/

struct snmp_bc_sensor snmp_bc_blade_sensors[] = {
        /* Blade CPU 1 Temperature Sensor */
        {
		.index = 1,
                .sensor = {
                        .Num = 1,
                        .Type = SAHPI_TEMPERATURE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
			.DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_DEGREES_C,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
                                        .Max = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 125,
                                                },
                                        },
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_TRUE,
                                .ReadThold  = SAHPI_STM_UP_MAJOR | SAHPI_STM_UP_CRIT,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.1.5.3.1.6.x",
				.loc_offset = 0,
                                .threshold_oids = {
					.UpCritical = ".1.3.6.1.4.1.2.3.51.2.22.1.5.4.1.6.x",
					.UpMajor    = ".1.3.6.1.4.1.2.3.51.2.22.1.5.4.1.7.x",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
			.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
                        .event_array = {
                                {
                                        .event = "0421C401", /* EN_PROC_HOT_CPU1 */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UPPER_MAJOR,
                                },
                                {
                                        .event = "0421C481", /* EN_CUTOFF_HI_OVER_TEMP_CPU1 */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UPPER_MAJOR,
                                },
                                {
                                        .event = "0421D081", /* EN_THERM_TRIP_CPU1 */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UPPER_MAJOR,
                                },
                                {
                                        .event = "0421D501", /* EN_PFA_HI_OVER_TEMP_CPU1 */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
 			.reading2event = {},
		},
                .comment = "Blade CPU 1 Temperature Sensor",
        },
        /* Blade CPU 2 Temperature Sensor */
        {
		.index = 2,
                .sensor = {
                        .Num = 2,
                        .Type = SAHPI_TEMPERATURE,
                        .Category = SAHPI_EC_THRESHOLD,
 			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_DEGREES_C,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
                                        .Max = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 125,
                                                },
                                        },
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_TRUE,
                                .ReadThold  = SAHPI_STM_UP_MAJOR | SAHPI_STM_UP_CRIT,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.1.5.3.1.7.x",
				.loc_offset = 0,
                                .threshold_oids = {
					.UpCritical = ".1.3.6.1.4.1.2.3.51.2.22.1.5.4.1.9.x",
					.UpMajor    = ".1.3.6.1.4.1.2.3.51.2.22.1.5.4.1.10.x",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
			.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
                        .event_array = {
				{
                                        .event = "0421C402", /* EN_PROC_HOT_CPU2 */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UPPER_MAJOR,
                                },
                                {
                                        .event = "0421C482", /* EN_CUTOFF_HI_OVER_TEMP_CPU2 */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UPPER_MAJOR,
                                },
                                {
                                        .event = "0421D082", /* EN_THERM_TRIP_CPU2 */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UPPER_MAJOR,
                                },
                                {
                                        .event = "0421D502", /* EN_PFA_HI_OVER_TEMP_CPU2 */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
				{},
                        },
  			.reading2event = {},
                },
                .comment = "Blade CPU 2 Temperature Sensor",
        },
        /* Blade CPU 3 Temperature Sensor */
        {
		.index = 3,
                .sensor = {
                        .Num = 3,
                        .Type = SAHPI_TEMPERATURE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_DEGREES_C,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
                                        .Max = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 125,
                                                },
                                        },
                                        .Min = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_TRUE,
                                .ReadThold  = SAHPI_STM_UP_MAJOR | SAHPI_STM_UP_CRIT,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.1.5.3.1.8.x",
				.loc_offset = 0,
                                .threshold_oids = {
					.UpCritical = ".1.3.6.1.4.1.2.3.51.2.22.1.5.4.1.12.x",
					.UpMajor    = ".1.3.6.1.4.1.2.3.51.2.22.1.5.4.1.13.x",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
			.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
                        .event_array = {
                                {
                                        .event = "0421C403", /* EN_PROC_HOT_CPU3 */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UPPER_MAJOR,
                                },
                                {
                                        .event = "0421C483", /* EN_CUTOFF_HI_OVER_TEMP_CPU3 */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UPPER_MAJOR,
                                },
                                {
                                        .event = "0421D083", /* EN_THERM_TRIP_CPU3 */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UPPER_MAJOR,
                                },
                                {
                                        .event = "0421D503", /* EN_PFA_HI_OVER_TEMP_CPU3 */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
 			.reading2event = {},
		},
                .comment = "Blade CPU 3 Temperature Sensor",
        },
        /* Blade CPU 4 Temperature Sensor */
        {
		.index = 4,
                .sensor = {
                        .Num = 4,
                        .Type = SAHPI_TEMPERATURE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_DEGREES_C,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
				.Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
                                        .Max = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 125,
                                                },
                                        },
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_TRUE,
                                .ReadThold  = SAHPI_STM_UP_MAJOR | SAHPI_STM_UP_CRIT,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.1.5.3.1.9.x",
				.loc_offset = 0,
                                .threshold_oids = {
					.UpCritical = ".1.3.6.1.4.1.2.3.51.2.22.1.5.4.1.15.x",
					.UpMajor    = ".1.3.6.1.4.1.2.3.51.2.22.1.5.4.1.16.x",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
			.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
                        .event_array = {
                                {
                                        .event = "0421C404", /* EN_PROC_HOT_CPU4 */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UPPER_MAJOR,
                                },
                                {
                                        .event = "0421C484", /* EN_CUTOFF_HI_OVER_TEMP_CPU4 */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UPPER_MAJOR,
                                },
                                {
                                        .event = "0421D084", /* EN_THERM_TRIP_CPU4 */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UPPER_MAJOR,
                                },
                                {
                                        .event = "0421D504", /* EN_PFA_HI_OVER_TEMP_CPU4 */
					.event_assertion = SAHPI_TRUE,
 					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
  			.reading2event = {},
                },
                .comment = "Blade CPU 4 Temperature Sensor",
        },
        /* Blade 1.25 Volt Sensor */
        {
		.index = 5,
                .sensor = {
                        .Num = 5,
                        .Type = SAHPI_VOLTAGE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_VOLTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
                                        .Max = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 3.3,
                                                },
                                        },
                                        .Nominal = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 1.25,
                                                },
                                        },
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_TRUE,
                                .ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.1.5.5.1.12.x",
				.loc_offset = 0,
                                .threshold_oids = {
					.UpMajor  = ".1.3.6.1.4.1.2.3.51.2.22.1.5.6.1.18.x",
					.LowMajor = ".1.3.6.1.4.1.2.3.51.2.22.1.5.6.1.19.x",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_LOWER_MAJOR |	SAHPI_ES_UPPER_MAJOR,
			.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
                        .event_array = {
                                {
                                        .event = "08001400", /* EN_PFA_HI_FAULT_1_25V */
  					.event_assertion = SAHPI_TRUE,
  					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {
                                        .event = "08001800", /* EN_PFA_LO_FAULT_1_25V */
 					.event_assertion = SAHPI_TRUE,
  					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_LOWER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
  			.reading2event = {},
                },
                .comment = "Blade 1.25 Volt Sensor",
        },
        /* Blade 1.5 Volt Sensor */
        {
		.index = 6,
                .sensor = {
                        .Num = 6,
                        .Type = SAHPI_VOLTAGE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_VOLTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
                                        .Max = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 4.4,
                                                },
                                        },
                                        .Nominal = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 1.5,
                                                },
                                        },
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_TRUE,
                                .ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.1.5.5.1.11.x",
				.loc_offset = 0,
                                .threshold_oids = {
					.UpMajor  = ".1.3.6.1.4.1.2.3.51.2.22.1.5.6.1.16.x",
					.LowMajor = ".1.3.6.1.4.1.2.3.51.2.22.1.5.6.1.17.x",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
			.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
                        .event_array = {
                                {
                                        .event = "0A041C00", /* EN_IO_1_5V_WARNING_HI */
 					.event_assertion = SAHPI_TRUE,
    					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {
                                        .event = "0A040C00", /* EN_IO_1_5V_WARNING_LOW */
 					.event_assertion = SAHPI_TRUE,
   					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_LOWER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
				{
					.event = "08041400", /* EN_PFA_HI_FAULT_1_5V */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_MAJOR,
					.recovery_state = SAHPI_ES_UNSPECIFIED,
				},
				{
					.event = "08041800", /* EN_PFA_LO_FAULT_1_5V */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_LOWER_MAJOR,
					.recovery_state = SAHPI_ES_UNSPECIFIED,
				},
				{},
                        },
 			.reading2event = {},
                 },
                .comment = "Blade 1.5 Volt Sensor",
        },
        /* Blade 2.5 Volt Sensor */
        {
		.index = 7,
                .sensor = {
                        .Num = 7,
                        .Type = SAHPI_VOLTAGE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_VOLTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
                                        .Max = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 4.4,
                                                },
                                        },
					.Nominal = {
  						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 2.5,
                                                },
                                        },
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_TRUE,
                                .ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.1.5.5.1.10.x",
				.loc_offset = 0,
                                .threshold_oids = {
					.UpMajor  = ".1.3.6.1.4.1.2.3.51.2.22.1.5.6.1.14.x",
					.LowMajor = ".1.3.6.1.4.1.2.3.51.2.22.1.5.6.1.15.x",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
			.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
                        .event_array = {
                                {
                                        .event = "0A031C00", /* EN_IO_2_5V_WARNING_HI */
 					.event_assertion = SAHPI_TRUE,
     					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_MAJOR,
					.recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {
                                        .event = "0A030C00", /* EN_IO_2_5V_WARNING_LOW */
 					.event_assertion = SAHPI_TRUE,
     					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_LOWER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
				{
					.event = "08031480", /* EN_PFA_HI_FAULT_2_5V */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_MAJOR,
					.recovery_state = SAHPI_ES_UNSPECIFIED,
				},
				{
					.event = "08031880", /* EN_PFA_LO_FAULT_2_5V */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_LOWER_MAJOR,
					.recovery_state = SAHPI_ES_UNSPECIFIED,
				},
                                {},
                        },
  			.reading2event = {},
                },
                .comment = "Blade 2.5 Volt Sensor",
        },
        /* Blade 3.3 Volt Sensor */
        {
		.index = 8,
                .sensor = {
                        .Num = 8,
                        .Type = SAHPI_VOLTAGE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_VOLTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
                                        .Max = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 4.4,
                                                },
                                        },
                                        .Nominal = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 3.3,
                                                },
                                        },
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_TRUE,
                                .ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.1.5.5.1.7.x",
				.loc_offset = 0,
                                .threshold_oids = {
					.UpMajor  = ".1.3.6.1.4.1.2.3.51.2.22.1.5.6.1.8.x",
					.LowMajor = ".1.3.6.1.4.1.2.3.51.2.22.1.5.6.1.9.x",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
			.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
			.event_array = {
                                {
                                        .event = "0A02DC00", /* EN_IO_3_3V_WARNING_HI */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {
                                        .event = "0A02CC00", /* EN_IO_3_3V_WARNING_LOW */
 					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_LOWER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
				{
					.event = "08033480", /* EN_PFA_HI_FAULT_3_35V */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_MAJOR,
					.recovery_state = SAHPI_ES_UNSPECIFIED,
				},
				/* FIXME:: New number when MM adds event */
				{
					.event = "FF032900", /* EN_MAJOR_LO_FAULT_3_35V */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_LOWER_MAJOR,
					.recovery_state = SAHPI_ES_UNSPECIFIED,
				},
                                {},
                        },
  			.reading2event = {},
                },
                .comment = "Blade 3.3 Volt Sensor",
        },
        /* Blade 5 Volt Sensor */
        {
		.index = 9,
                .sensor = {
                        .Num = 9,
                        .Type = SAHPI_VOLTAGE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_VOLTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
                                        .Max = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 6.7,
                                                },
                                        },
                                        .Nominal = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 5,
                                                },
                                        },
                                        .Min = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_TRUE,
                                .ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.1.5.5.1.6.x",
				.loc_offset = 0,
                                .threshold_oids = {
					.UpMajor  = ".1.3.6.1.4.1.2.3.51.2.22.1.5.6.1.6.x",
					.LowMajor = ".1.3.6.1.4.1.2.3.51.2.22.1.5.6.1.7.x",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
			.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
                        .event_array = {
                                {
                                        .event = "0A035C00", /* EN_IO_5V_WARNING_HI */
 					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {
                                        .event = "0A034C00", /* EN_IO_5V_WARNING_LOW */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_LOWER_CRIT,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {
                                        .event = "08035500", /* EN_PFA_HI_FAULT_5V */
 					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {
                                        .event = "08035800", /* EN_PFA_LO_FAULT_5V */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_LOWER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
  			.reading2event = {},
                },
                .comment = "Blade 5 Volt Sensor",
        },
        /* Blade 12 Volt Sensor */
        {
		.index = 10,
                .sensor = {
                        .Num = 10,
                        .Type = SAHPI_VOLTAGE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_VOLTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
                                        .Max = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 16,
                                                },
                                        },
                                        .Nominal = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 12,
                                                },
                                        },
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_TRUE,
                                .ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.1.5.5.1.8.x",
				.loc_offset = 0,
                                .threshold_oids = {
					.UpMajor  = ".1.3.6.1.4.1.2.3.51.2.22.1.5.6.1.10.x",
					.LowMajor = ".1.3.6.1.4.1.2.3.51.2.22.1.5.6.1.11.x",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
			.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
                        .event_array = {
                                {
                                        .event = "0A037C00", /* EN_IO_12V_WARNING_HI */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {
                                        .event = "0A036C00", /* EN_IO_12V_WARNING_LOW */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_LOWER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {
                                        .event = "06037500", /* EN_PFA_HI_FAULT_12V_PLANAR */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {
                                        .event = "06037800", /* EN_PFA_LO_FAULT_12V_PLANAR */
 					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_LOWER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
  			.reading2event = {},
                },
                .comment = "Blade 12 Volt Sensor",
        },
        /* Blade VRM 1 Voltage Sensor */
        {
		.index = 11,
                .sensor = {
                        .Num = 11,
                        .Type = SAHPI_VOLTAGE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_VOLTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
                                        .Max = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 3.6,
                                                },
                                        },
                                        .Min = {
  						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_FALSE,
                                .ReadThold  = 0,
				.WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.1.5.5.1.13.x",
				.loc_offset = 0,
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
			.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
                        .event_array = {
                                {
                                        .event = "04401501", /* EN_PFA_HI_FAULT_VRM1 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {
                                        .event = "04401801", /* EN_PFA_LO_FAULT_VRM1 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_LOWER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
   			.reading2event = {},
		},
		.comment = "Blade VRM 1 Voltage Sensor",
        },
        /* Blade Operational Status Sensor */
        {
		.index = 12,
                .sensor = {
                        .Num = 12,
                        .Type = SAHPI_OPERATIONAL,
                        .Category = SAHPI_EC_AVAILABILITY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_RUNNING | SAHPI_ES_OFF_LINE |
                                  SAHPI_ES_DEGRADED | SAHPI_ES_INSTALL_ERROR,
                        .DataFormat = {
				.IsSupported = SAHPI_TRUE,
				.ReadingType = SAHPI_SENSOR_READING_TYPE_INT64,
				.BaseUnits = SAHPI_SU_UNSPECIFIED,
				.ModifierUnits = SAHPI_SU_UNSPECIFIED,
				.ModifierUse = SAHPI_SMUU_NONE,
				.Percentage = SAHPI_FALSE,
				.Range = {
					.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
					.Max = {
						.IsSupported = SAHPI_TRUE,
						.Type = SAHPI_SENSOR_READING_TYPE_INT64,
						.Value = {
							.SensorInt64 = 9,
						},
					},
					.Min = {
						.IsSupported = SAHPI_TRUE,
						.Type = SAHPI_SENSOR_READING_TYPE_INT64,
						.Value = {
							.SensorInt64 = 0,
						},
					},
				},
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.1.5.1.1.5.x",
				.loc_offset = 0,
                        },
                        .cur_state = SAHPI_ES_RUNNING,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_DEGRADED | SAHPI_ES_OFF_LINE | SAHPI_ES_INSTALL_ERROR,
			.deassert_mask = SAHPI_ES_DEGRADED | SAHPI_ES_OFF_LINE | SAHPI_ES_INSTALL_ERROR,
                        .event_array = {
                                {
                                        .event = "0E00A00x", /* EN_BLADE_x_INSUFFICIENT_PWR */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0F00C00x", /* EN_BLADE_1_SHUTDOWN_OVER_PWR_BUDGET */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0E01200x", /* EN_BLADE_2_UNIDENTIABLE_HW_DENY_POWER */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0401A000", /* EN_CPU_BD_POWER_FAULT */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04018000", /* EN_CPU_BD_VOLTAGE_FAULT */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0401E000", /* EN_CPU_INVALID_CONFIG */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04300201", /* EN_IERR_CPU1 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04300202", /* EN_IERR_CPU2 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04300203", /* EN_IERR_CPU3 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04300204", /* EN_IERR_CPU4 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0421C081", /* EN_OVER_TEMP_CPU1 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0421C082", /* EN_OVER_TEMP_CPU2 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0421C083", /* EN_OVER_TEMP_CPU3 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0421C084", /* EN_OVER_TEMP_CPU4 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00000069", /* EN_DASD */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "06016000", /* EN_IO_BD_FAULT */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
				{
                                        .event = "0601A000", /* EN_IO_BD_POWER_FAULT */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "06018000", /* EN_IO_BD_VOLTAGE_FAULT */
 					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00028000", /* EN_FAULT_POWER_GOOD */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00028001", /* EN_FAULT_SYS_POWER_GOOD */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04428000", /* EN_FAULT_VRM_POWER_GOOD */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04428001", /* EN_FAULT_VRM_POWER_GOOD_1 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04428002", /* EN_FAULT_VRM_POWER_GOOD_2 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04428003", /* EN_FAULT_VRM_POWER_GOOD_3 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04428004", /* EN_FAULT_VRM_POWER_GOOD_4 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
				{
                                        .event = "04000000", /* EN_AUTO_BIOS_ALERT */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
				{
					.event = "0D01E000", /* EN_HSDC_FAULT */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00216030", /* EN_IPMI_SM_INIT_FAIL */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0021601C", /* EN_IPMI_SYS_BOARD_FAIL */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0021603E", /* EN_IPMI_PCI_BUS_TIMEOUT */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0021603F", /* EN_IPMI_BIOS_HALTED_UNSPEC */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "08016080", /* EN_PWR_CONTROLLER_TIMEOUT */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "05200000", /* EN_MEMORY_FAIL */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0A000281", /* EN_UNCORRECT_DIMM_1_ERR */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
					.event = "0A000282", /* EN_UNCORRECT_DIMM_2_ERR */
  					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
					.event = "0A000283", /* EN_UNCORRECT_DIMM_3_ERR */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
 					.event = "0A000284", /* EN_UNCORRECT_DIMM_4_ERR */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
					.event = "0A000285", /* EN_UNCORRECT_DIMM_5_ERR */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
					.event = "0A000286", /* EN_UNCORRECT_DIMM_6_ERR */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
					.event = "0A000287", /* EN_UNCORRECT_DIMM_7_ERR */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
					.event = "0A000288", /* EN_UNCORRECT_DIMM_8_ERR */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00216012", /* EN_IPMI_UNCORRECT_BUS_ERR */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00216003", /* EN_IPMI_DIMM_ERR */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "06C16000", /* EN_MEM_MOD_BUS_UNCORR_ERR */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0E00E00x", /* EN_BLADE_x_NO_PWR_VPD */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0E01000x", /* EN_BLADE_x_NO_MGT_VPD */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0E00800x", /* EN_BLADE_x_COMM_FAIL */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0E00C00x", /* EN_BLADE_x_THROTTLED */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "00000077", /* EN_BOOT_FAIL */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0A000000", /* EN_CKVM_FAULT */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04204001", /* EN_CPU_1_DISABLED */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04204002", /* EN_CPU_2_DISABLED */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04204003", /* EN_CPU_3_DISABLED */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04204004", /* EN_CPU_4_DISABLED */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04306201", /* EN_IERR_CPU_RESTART1 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04306202", /* EN_IERR_CPU_RESTART2 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04306203", /* EN_IERR_CPU_RESTART3 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04306204", /* EN_IERR_CPU_RESTART4 */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0000006F", /* EN_NC_VOLT */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "09025000", /* EN_FP_NP */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0421D401", /* EN_CPU1_TEMP_WARN */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0421D402", /* EN_CPU2_TEMP_WARN */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0E00600x", /* EN_BLADE_x_CFG_FAIL */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_INSTALL_ERROR,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0EC00001", /* EN_BEM_1_FAULT */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_INSTALL_ERROR,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0EC00002", /* EN_BEM_2_FAULT */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_INSTALL_ERROR,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "08100080", /* EN_PWR_CONTROLLER_MISMATCH */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_INSTALL_ERROR,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0D000281", /* EN_BSE_LEGACY_DC1_DONT_WORK */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_INSTALL_ERROR,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0D000282", /* EN_BSE_LEGACY_DC2_DONT_WORK */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_INSTALL_ERROR,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04000300", /* EN_POWER_JUMPER_NP */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_INSTALL_ERROR,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "04000280", /* EN_BLADE_INCOMPATIABLE */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_INSTALL_ERROR,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {},
                        },
   			.reading2event = {
				/* 0 = unknown */
				{
					.num = 1,
                                        .rangemap = {
						.Flags = SAHPI_SRF_MIN,
						.Min = {
							.Value = {
								.SensorInt64 = 1,
							},
						},
					},
					.state = SAHPI_ES_UNSPECIFIED,
                                },
				/* 1 = good */
				{
					.num = 2,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorInt64 = 1, 
							},
						},
					},
					.state = SAHPI_ES_RUNNING,
				},
				/* 2 = warning */
 				{
					.num = 3,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorInt64 = 2,
							},
						},
					},
					.state = SAHPI_ES_DEGRADED,
                                },
				/* 3 = bad, 4 = kernelMode, 5 = discovering, 6 = commError
				   7 = noPower, 8 = flashing */
 				{
					.num = 4,
                                        .rangemap = {
						.Flags = SAHPI_SRF_MIN | SAHPI_SRF_MAX,
						.Min = {
							.Value = {
								.SensorInt64 = 3,
							},
						},
						.Max = {
							.Value = {
								.SensorInt64 = 8,
							},
						},

					},
					.state = SAHPI_ES_OFF_LINE,
                                },
				/* 9 = initFailure */	
 				{
					.num = 5,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorInt64 = 9,
							},
						},
					},
					.state = SAHPI_ES_INSTALL_ERROR,
                                },
			},
		},
                .comment = "Blade Operational Status Sensor",
        },
	/* Blade NMI Status Sensor */
        {
		.index = 13,
                .sensor = {
                        .Num = 13,
                        .Type = SAHPI_CRITICAL_INTERRUPT,
                        .Category = SAHPI_EC_STATE,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_STATE_ASSERTED | SAHPI_ES_STATE_DEASSERTED,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_STATE_DEASSERTED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_STATE_ASSERTED,
			.deassert_mask = SAHPI_ES_STATE_ASSERTED,
                        .event_array = {
                                {
					.event = "0000007E", /* EN_SYSERR_LED_ONLY */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_STATE_ASSERTED,
                                        .recovery_state = SAHPI_ES_STATE_DEASSERTED,
                                },
                                {},
                        },
   			.reading2event = {},
               },
                .comment = "Blade NMI Status Sensor",
        },
	/* Blade Management Bus Operational Status Sensor - event only */
        {
		.index = 14,
                .sensor = {
                        .Num = 14,
                        .Type = SAHPI_OPERATIONAL,
                        .Category = SAHPI_EC_AVAILABILITY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
			.Events = SAHPI_ES_RUNNING | SAHPI_ES_OFF_LINE,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_RUNNING,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_OFF_LINE,
			.deassert_mask = SAHPI_ES_OFF_LINE,
                        .event_array = {
                                {
                                        .event = "0E02200x", /* EN_STCONN_FAIL_BLADE_x */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {},
                        },
   			.reading2event = {},
                },
                .comment = "Blade Management Bus Operations Sensor",
        },

        {} /* Terminate array with a null element */
};

/* Blade IPMI Sensors */
/* NOTE: Define IPMI Tags as uppercase */
#define SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR 14
struct snmp_bc_ipmi_sensor snmp_bc_blade_ipmi_sensors[] = {
        /* Blade CPU 1 Temperature Sensor */
        {
		.ipmi_tag = "CPU1 TEMP",
		.ipmi_tag_alias1 = "CPU 1 TEMP",
		.ipmi = {
			.index = 1,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 1,
				.Type = SAHPI_TEMPERATURE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_DEGREES_C,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 125,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_UP_MAJOR | SAHPI_STM_UP_CRIT,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpCritical = "discovered",
						.UpMajor    = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.event_array = {
					{
						.event = "FFFFFF1C", /* EN_GENERIC_HI_CRIT_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_CRIT,
						.recovery_state = SAHPI_ES_UPPER_MAJOR,
					},
					{
						.event = "FFFFFF1D", /* EN_GENERIC_HI_WARN_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade CPU 1 Temperature Sensor",
		},
	},
        /* Blade CPU 2 Temperature Sensor */
        {
		.ipmi_tag = "CPU2 TEMP",
		.ipmi_tag_alias1 = "CPU 2 TEMP",
		.ipmi = {
			.index = 2,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 2,
				.Type = SAHPI_TEMPERATURE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_DEGREES_C,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 125,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_UP_MAJOR | SAHPI_STM_UP_CRIT,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpCritical = "discovered",
						.UpMajor    = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.event_array = {
					{
						.event = "FFFFFF20", /* EN_GENERIC_HI_CRIT_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_CRIT,
						.recovery_state = SAHPI_ES_UPPER_MAJOR,
					},
					{
						.event = "FFFFFF21", /* EN_GENERIC_HI_WARN_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade CPU 2 Temperature Sensor",
		},
        },
        /* Blade CPU 3 Temperature Sensor */
        {
		.ipmi_tag = "CPU3 TEMP",
		.ipmi_tag_alias1 = "CPU 3 TEMP",
		.ipmi = {
			.index = 3,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 3,
				.Type = SAHPI_TEMPERATURE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_DEGREES_C,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 125,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_UP_MAJOR | SAHPI_STM_UP_CRIT,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpCritical = "discovered",
						.UpMajor    = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.event_array = {
					{
						.event = "FFFFFF22", /* EN_GENERIC_HI_CRIT_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_CRIT,
						.recovery_state = SAHPI_ES_UPPER_MAJOR,
					},
					{
						.event = "FFFFFF23", /* EN_GENERIC_HI_WARN_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade CPU 3 Temperature Sensor",
		},
        },
        /* Blade CPU 4 Temperature Sensor */
        {
		.ipmi_tag = "CPU4 TEMP",
		.ipmi_tag_alias1 = "CPU 4 TEMP",
		.ipmi = {
			.index = 4,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 4,
				.Type = SAHPI_TEMPERATURE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_DEGREES_C,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 125,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_UP_MAJOR | SAHPI_STM_UP_CRIT,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpCritical = "discovered",
						.UpMajor    = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.event_array = {
					{
						.event = "FFFFFF24", /* EN_GENERIC_HI_CRIT_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_CRIT,
						.recovery_state = SAHPI_ES_UPPER_MAJOR,
					},
					{
						.event = "FFFFFF25", /* EN_GENERIC_HI_WARN_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade CPU 4 Temperature Sensor",
		},
	},
        /* Blade 0.9 Volt Sensor */
        {
		.ipmi_tag = "PLANAR 0.9V",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 5,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 5,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 1.5,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0.9,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFFF1", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFFF2", /* EN_GENERIC_LOWER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade 0.9 Volt Sensor",
		},
        },
        /* Blade 1.2 Volt Sensor */
        {
		.ipmi_tag = "1.2V SENSE",
		.ipmi_tag_alias1 = "PLANAR 1.2V",
		.ipmi = {
			.index = 6,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 6,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 3.3,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 1.2,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "08001401", /* EN_PFA_HI_FAULT_1_2V */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "08001801", /* EN_PFA_LO_FAULT_1_2V */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade 1.2 Volt Sensor",
		},
        },
        /* Blade Standby 1.2 Volt Sensor */
        {
		.ipmi_tag = "1.2VSB SENSE",
		.ipmi_tag_alias1 = "PLANAR 1.2VSB",
		.ipmi = {
			.index = 7,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 7,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 3.3,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 1.2,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "0A00BC02", /* EN_1_2VS_WARNING_HI */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0A00AC02", /* EN_1_2VS_WARNING_LOW */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade Standby 1.2 Volt Sensor",
		},
        },
	/* Blade 1.5 Volt Sensor */
        {
		.ipmi_tag = "1.5V SENSE",
		.ipmi_tag_alias1 = "PLANAR 1.5V",
		.ipmi = {
			.index = 8,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 8,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 4.4,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 1.5,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					/*  No IPMI unique events */
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade 1.5 Volt Sensor",
		},
        },
	/* Blade Standby 1.5 Volt Sensor */
        {
		.ipmi_tag = "1.5VSB SENSE",
		.ipmi_tag_alias1 = "PLANAR 1.5VSB",
		.ipmi = {
			.index = 9,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 9,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 4.4,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 1.5,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "0A041C02", /* EN_1_5VS_WARNING_HI */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0A040C02", /* EN_1_5VS_WARNING_LOW */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade Standby 1.5 Volt Sensor",
		},
        },
        /* Blade 1.8 Volt Sensor */
        {
		.ipmi_tag = "1.8V SENSE",
		.ipmi_tag_alias1 = "PLANAR 1.8V",
		.ipmi = {
			.index = 10,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 10,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 4.4,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 1.8,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.LowMajor = "discovered",
						.UpMajor  = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
#if 0
					{
						.event = "0A07BC00", /* EN_IO_1_8V_WARNING_HI */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0A07AC00", /* EN_IO_1_8V_WARNING_LOW */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
#endif
					{
						.event = "0807B400", /* EN_PFA_HI_FAULT_1_8V */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0807B800", /* EN_PFA_LO_FAULT_1_8V */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade 1.8 Volt Sensor",
		},
        },
        /* Blade Standby 1.8 Volt Sensor */
        {
		.ipmi_tag = "1.8VSB SENSE",
		.ipmi_tag_alias1 = "PLANAR 1.8VSB",
		.ipmi = {
			.index = 11,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 11,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 4.4,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 1.8,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.LowMajor = "discovered",
						.UpMajor  = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "0A07BC02", /* EN_1_8VS_WARNING_HI */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0A07AC02", /* EN_1_8VS_WARNING_LOW */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade Standby 1.8 Volt Sensor",
		},
        },
	/* Blade 2.5 Volt Sensor */
        {
		.ipmi_tag = "2.5V SENSE",
		.ipmi_tag_alias1 = "PLANAR 2.5V",
		.ipmi = {
			.index = 12,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 12,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 4.4,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 2.5,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					/* No IPMI unique events */
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade 2.5 Volt Sensor",
		},
        },
        /* Blade Standby 2.5 Volt Sensor */
        {
		.ipmi_tag = "2.5VSB SENSE",
		.ipmi_tag_alias1 = "PLANAR 2.5VSB",
		.ipmi = {
			.index = 13,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 13,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 4.4,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 2.5,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
#if 0
					{
						.event = "0A031C01", /* EN_IO_2_5VS_WARNING_HI */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0A030C01", /* EN_IO_2_5VS_WARNING_LO */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
#endif
					{
						.event = "0A031C02", /* EN_2_5VS_WARNING_HI */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0A030C02", /* EN_2_5VS_WARNING_LOW */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade Standby 2.5 Volt Sensor",
		},
        },
        /* Blade 3.3 Volt Sensor */
        {
		.ipmi_tag = "3.3V SENSE",
		.ipmi_tag_alias1 = "PLANAR 3.3V",
		.ipmi = {
			.index = 14,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 14,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 4.4,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 3.3,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFFF3", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFFF4", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade 3.3 Volt Sensor",
		},
        },
        /* Blade Standby 3.3 Volt Sensor */
        {
		.ipmi_tag = "3.3VSB SENSE",
		.ipmi_tag_alias1 = "PLANAR 3.3VSB",
		.ipmi = {
			.index = 15,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 15,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 4.4,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 3.3,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
#if 0
					{
						.event = "0A02DC01", /* EN_IO_3_3VS_WARNING_HI */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0A02CC01", /*EN_IO_3_3VS_WARNING_LOW  */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
#endif
					{
						.event = "0A02DC02", /* EN_3_3VS_WARNING_HI */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0A02CC02", /* EN_3_3VS_WARNING_LOW */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade Standby 3.3 Volt Sensor",
		},
        },
        /* Blade 5 Volt Sensor */
        {
		.ipmi_tag = "5V SENSE",
		.ipmi_tag_alias1 = "PLANAR 5V",
		.ipmi = {
			.index = 16,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 16,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 6.7,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 5,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFFF5", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFFF6", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade 5 Volt Sensor",
		},
        },
        /* Blade Standby 5 Volt Sensor */
        {
		.ipmi_tag = "5VSB SENSE",
		.ipmi_tag_alias1 = "PLANAR 5VSB",
		.ipmi = {
			.index = 17,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 17,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 6.7,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 5,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "0A035C02", /* EN_5VS_WARNING_HI */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0A034C02", /* EN_5VS_WARNING_LOW */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade Standby 5 Volt Sensor",
		},
        },
        /* Blade -5 Volt Sensor */
        {
		.ipmi_tag = "-5V SENSE",
		.ipmi_tag_alias1 = "PLANAR -5V",
		.ipmi = {
			.index = 18,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 18,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = -5,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = -6.7,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
#if 0
					{
						.event = "0A03DC00", /* EN_IO_N5V_WARNING_HI */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0A03CC00", /* EN_IO_N5V_WARNING_LOW */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
#endif
					{
						.event = "0803D500", /* EN_PFA_HI_FAULT_N5V */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0803D800", /* EN_PFA_LO_FAULT_N5V */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade -5 Volt Sensor",
		},
        },
        /* Blade 12 Voltage Sensor */
        {
		.ipmi_tag = "12V SENSE",
		.ipmi_tag_alias1 = "PLANAR 12V",
		.ipmi = {
			.index = 19,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 19,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 16,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 12,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFFF7", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFFF8", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade 12 Volt Sensor",
		},
        },
        /* Blade Standby 12 Volt Sensor */
        {
		.ipmi_tag = "12VSB SENSE",
		.ipmi_tag_alias1 = "PLANAR 12VSB",
		.ipmi = {
			.index = 20,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 20,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 16,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 12,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
#if 0
					{
						.event = "0A037C01", /* EN_IO_12VS_WARNING_HI */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0A036C01", /* EN_IO_12VS_WARNING_LOW */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
#endif
					{
						.event = "0A037C02", /* EN_12VS_WARNING_HI */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0A036C02", /* EN_12VS_WARNING_LOW */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade Standby 12 Volt Sensor",
		},
        },
        /* Blade CPU 1 Core Voltage Sensor */
        {
		.ipmi_tag = "CPU 1 VCORE",
		.ipmi_tag_alias1 = "CPU1 VCORE",
		.ipmi = {
			.index = 21,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 21,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 3.67,
							},
						},
						/* No nominal reading - depends on CPU versions and number */
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFFF9", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFFFA", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade CPU 1 Core Voltage Sensor",
		},
        },
        /* Blade CPU 2 Core Voltage Sensor */
        {
		.ipmi_tag = "CPU 2 VCORE",
		.ipmi_tag_alias1 = "CPU2 VCORE",
		.ipmi = {
			.index = 22,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 22,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 3.67,
							},
						},
						/* No nominal reading - depends on CPU versions and number */
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFFFB", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFFFC", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade CPU 2 Core Voltage Sensor",
		},
        },
        /* Blade CPU 3 Core Voltage Sensor */
        {
		.ipmi_tag = "CPU 3 VCORE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 23,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 23,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 3.67,
							},
						},
						/* No nominal reading - depends on CPU versions and number */
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFFFD", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFFFE", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade CPU 3 Core Voltage Sensor",
		},
        },
        /* Blade CPU 4 Core Voltage Sensor */
        {
		.ipmi_tag = "CPU 4 VCORE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 24,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 24,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 3.67,
							},
						},
						/* No nominal reading - depends on CPU versions and number */
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFF10", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFF11", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade CPU 4 Core Voltage Sensor",
		},
        },
        /* Blade Battery Voltage Sensor */
        {
		.ipmi_tag = "VBATT SENSE",
		.ipmi_tag_alias1 = "PLANAR VBAT",
		.ipmi = {
			.index = 25,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 25,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 4.4,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 3.3,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFF12", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFF13", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade Battery Voltage Sensor",
		},
        },
	/* Blade Memory Bank 1 Temperature Sensor */
        {
		.ipmi_tag = "BANK1 TEMP",
		.ipmi_tag_alias1 = "BANK 1 TEMP",
		.ipmi = {
			.index = 26,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 26,
				.Type = SAHPI_TEMPERATURE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_DEGREES_C,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 125,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_UP_MAJOR | SAHPI_STM_UP_CRIT,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpCritical = "discovered",
						.UpMajor    = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.event_array = {
					{
						.event = "FFFFFF14", /* EN_GENERIC_HI_CRIT_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_CRIT,
						.recovery_state = SAHPI_ES_UPPER_MAJOR,
					},
					{
						.event = "FFFFFF15", /* EN_GENERIC_HI_WARN_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade Memory Bank 1 Temperature Sensor",
		},
	},
	/* Blade Memory Bank 2 Temperature Sensor */
        {
		.ipmi_tag = "BANK2 TEMP",
		.ipmi_tag_alias1 = "BANK 2 TEMP",
		.ipmi = {
			.index = 27,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 27,
				.Type = SAHPI_TEMPERATURE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_DEGREES_C,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 125,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_UP_MAJOR | SAHPI_STM_UP_CRIT,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpCritical = "discovered",
						.UpMajor    = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.event_array = {
					{
						.event = "FFFFFF16", /* EN_GENERIC_HI_CRIT_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_CRIT,
						.recovery_state = SAHPI_ES_UPPER_MAJOR,
					},
					{
						.event = "FFFFFF17", /* EN_GENERIC_HI_WARN_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade Memory Bank 2 Temperature Sensor",
		},
	},
	/* Blade Memory Bank 3 Temperature Sensor */
        {
		.ipmi_tag = "BANK3 TEMP",
		.ipmi_tag_alias1 = "BANK 3 TEMP",
		.ipmi = {
			.index = 28,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 28,
				.Type = SAHPI_TEMPERATURE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_DEGREES_C,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 125,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_UP_MAJOR | SAHPI_STM_UP_CRIT,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpCritical = "discovered",
						.UpMajor    = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.event_array = {
					{
						.event = "FFFFFF18", /* EN_GENERIC_HI_CRIT_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_CRIT,
						.recovery_state = SAHPI_ES_UPPER_MAJOR,
					},
					{
						.event = "FFFFFF19", /* EN_GENERIC_HI_WARN_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade Memory Bank 3 Temperature Sensor",
		},
	},
	/* Blade Memory Bank 4 Temperature Sensor */
        {
		.ipmi_tag = "BANK4 TEMP",
		.ipmi_tag_alias1 = "BANK 4 TEMP",
		.ipmi = {
			.index = 29,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BLADE_SENSOR + 29,
				.Type = SAHPI_TEMPERATURE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_DEGREES_C,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 125,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_UP_MAJOR | SAHPI_STM_UP_CRIT,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpCritical = "discovered",
						.UpMajor    = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.event_array = {
					{
						.event = "FFFFFF1A", /* EN_GENERIC_HI_CRIT_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_CRIT,
						.recovery_state = SAHPI_ES_UPPER_MAJOR,
					},
					{
						.event = "FFFFFF1B", /* EN_GENERIC_HI_WARN_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "Blade Memory Bank 4 Temperature Sensor",
		},
	},

        {} /* Terminate array with a null element */
};

/**************************************
 * Blade Expansion Module (BEM) Sensors
 **************************************/

struct snmp_bc_sensor snmp_bc_bem_sensors[] = {
#if 1
        /* BSE Temperature Sensor */ /* Legacy Blades */
        {
		.index = 1,
                .sensor = {
                        .Num = 1,
                        .Type = SAHPI_TEMPERATURE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_DEGREES_C,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
                                        .Max = {
  						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 125,
                                                },
                                        },
                                        .Min = {
 						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_TRUE,
                                .ReadThold  = SAHPI_STM_UP_MAJOR | SAHPI_STM_UP_CRIT,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.1.5.3.1.10.x",
				.loc_offset = 0,
                                .threshold_oids = {
					.UpCritical  = ".1.3.6.1.4.1.2.3.51.2.22.1.5.4.1.18.x",
					.UpMajor = ".1.3.6.1.4.1.2.3.51.2.22.1.5.4.1.19.x",
                                },
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
			.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
                        .event_array = {
				{
					.event = "0621C481", /* EN_CUTOFF_HI_OVER_TEMP_BEM */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_CRIT,
					.recovery_state = SAHPI_ES_UPPER_MAJOR,
				},
				{
					.event = "0681C482", /* EN_CUTOFF_HI_OVER_TEMP_DASD1_2 */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_CRIT,
					.recovery_state = SAHPI_ES_UPPER_MAJOR,
				},
				{
					.event = "0681C483", /* EN_CUTOFF_HI_OVER_TEMP_DASD1_3 */
					.event_assertion = SAHPI_TRUE, 
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_CRIT,
					.recovery_state = SAHPI_ES_UPPER_MAJOR,
				},
				{
					.event = "0621C081", /* EN_OVER_TEMP_BEM */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_CRIT,
					.recovery_state = SAHPI_ES_UPPER_MAJOR,
				},
				{
					.event = "0621D481", /* EN_PFA_HI_OVER_TEMP_BEM */
					.event_assertion = SAHPI_TRUE, 
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_MAJOR,
					.recovery_state = SAHPI_ES_UNSPECIFIED,
				},
                                {},
			},
  			.reading2event = {},
                },
                .comment = "BSE Temperature Sensor",
        },
#endif
        /* BEM Voltage Sensor - event only */
        {
		.index = 2,
                .sensor = {
                        .Num = 2,
                        .Type = SAHPI_VOLTAGE,
                        .Category = SAHPI_EC_SEVERITY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
			.Events = SAHPI_ES_OK | SAHPI_ES_MAJOR_FROM_LESS,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_OK,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_MAJOR_FROM_LESS,
			.deassert_mask = SAHPI_ES_MAJOR_FROM_LESS,
                        .event_array = {
				{
                                        .event = "06800000", /* EN_FAULT_DASD */
 					.event_assertion = SAHPI_TRUE,
                                        .event_state = SAHPI_ES_CRITICAL,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .recovery_state = SAHPI_ES_OK,
                                },
                                {
                                        .event = "0E840002", /* EN_BEM_1_5V_FAULT */
 					.event_assertion = SAHPI_TRUE,
                                        .event_state = SAHPI_ES_CRITICAL,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .recovery_state = SAHPI_ES_OK,
                                },
                                {
                                        .event = "0E87A002", /* EN_BEM_1_8V_FAULT */
 					.event_assertion = SAHPI_TRUE,
                                        .event_state = SAHPI_ES_CRITICAL,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .recovery_state = SAHPI_ES_OK,
                                },
                                {
                                        .event = "0E87A402", /* EN_BEM_1_8V_WARNING_HI */
 					.event_assertion = SAHPI_TRUE,
                                        .event_state = SAHPI_ES_MAJOR_FROM_LESS,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .recovery_state = SAHPI_ES_OK,
                                },
                                {
                                        .event = "0E87A802", /* EN_BEM_1_8V_WARNING_LOW */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_MAJOR_FROM_LESS,
                                        .recovery_state = SAHPI_ES_OK,
                                },
                                {
                                        .event = "0E830002", /* EN_BEM_2_5V_FAULT */
 					.event_assertion = SAHPI_TRUE,
                                        .event_state = SAHPI_ES_CRITICAL,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .recovery_state = SAHPI_ES_OK,
                                },
				{
                                        .event = "0E830402", /* EN_BEM_2_5V_WARNING_HI */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_MAJOR_FROM_LESS,
                                        .recovery_state = SAHPI_ES_OK,
                                },
				{
                                        .event = "0E830802", /* EN_BEM_2_5V_WARNING_LOW */
 					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_MAJOR_FROM_LESS,
                                        .recovery_state = SAHPI_ES_OK,
                                },
				{
					.event = "0E832002", /* EN_BEM_3_3V_FAULT */
					.event_assertion = SAHPI_TRUE,
					.event_state = SAHPI_ES_CRITICAL,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.recovery_state = SAHPI_ES_OK,
				},
                                {
                                        .event = "0E834002", /* EN_BEM_5V_FAULT */
 					.event_assertion = SAHPI_TRUE,
                                        .event_state = SAHPI_ES_CRITICAL,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .recovery_state = SAHPI_ES_OK,
                                },
                                {
                                        .event = "0E836002", /* EN_BEM_12V_FAULT */
 					.event_assertion = SAHPI_TRUE,
                                        .event_state = SAHPI_ES_CRITICAL,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .recovery_state = SAHPI_ES_OK,
                                },
                                {
                                        .event = "0E83C002", /* EN_BEM_18V_FAULT */
 					.event_assertion = SAHPI_TRUE,
                                        .event_state = SAHPI_ES_CRITICAL,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .recovery_state = SAHPI_ES_OK,
                                },
 				{
					.event = "0E83C402", /* EN_BEM_18V_WARNING_HI */
  					.event_assertion = SAHPI_TRUE,
                                        .event_state = SAHPI_ES_MAJOR_FROM_LESS,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .recovery_state = SAHPI_ES_OK,
                                },
				{
					.event = "0E83C802", /* EN_BEM_18V_WARNING_LOW */
  					.event_assertion = SAHPI_TRUE,
      					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_MAJOR_FROM_LESS,
                                        .recovery_state = SAHPI_ES_OK,
                                },
                                {},
                        },
  			.reading2event = {},
                 },
                .comment = "BEM Voltage Sensor",
        },
	/* BEM DASD (SCSI ID=2) Operational Sensor - event only */
        {
		.index = 3,
                .sensor = {
                        .Num = 3,
                        .Type = SAHPI_OPERATIONAL,
                        .Category = SAHPI_EC_AVAILABILITY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
			.Events = SAHPI_ES_RUNNING | SAHPI_ES_OFF_LINE,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_RUNNING,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_OFF_LINE,
			.deassert_mask = SAHPI_ES_OFF_LINE,
                        .event_array = {
                                {
                                        .event = "06801002", /* EN_FAULT_DASD1_SCSI_ID_2 */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {},
                        },
   			.reading2event = {},
                },
                .comment = "BEM DASD (SCSI ID=2) Operational Sensor",
        },
	/* BEM DASD (SCSI ID=3) Operational Sensor - event only */
        {
		.index = 4,
                .sensor = {
                        .Num = 4,
                        .Type = SAHPI_OPERATIONAL,
                        .Category = SAHPI_EC_AVAILABILITY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
			.Events = SAHPI_ES_RUNNING | SAHPI_ES_OFF_LINE,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_RUNNING,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_OFF_LINE,
			.deassert_mask = SAHPI_ES_OFF_LINE,
                        .event_array = {
                                {
                                        .event = "06801003", /* EN_FAULT_DASD1_SCSI_ID_3 */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {},
                        },
   			.reading2event = {},
                },
                .comment = "BEM DASD (SCSI ID=3) Operational Sensor",
        },

        {} /* Terminate array with a null element */
};

/* BEM IPMI Sensors */
/* NOTE: Define IPMI Tags as uppercase */

#define SNMP_BC_LAST_NON_IPMI_BEM_SENSOR 4
struct snmp_bc_ipmi_sensor snmp_bc_bem_ipmi_sensors[] = {
	/* BSE Temperature Sensor */
        {
		.ipmi_tag = "BSE TEMP SENSE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 1,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 1,
				.Type = SAHPI_TEMPERATURE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_DEGREES_C,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 125,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_UP_MAJOR | SAHPI_STM_UP_CRIT,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpCritical = "discovered",
						.UpMajor    = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.event_array = {
					/* FIXME:: Add events */
					{},
				},
				.reading2event = {},
			},
			.comment = "BSE Temperature Sensor",
		},
	},
	/* BSE Vcc Volt Sensor */
        {
		.ipmi_tag = "BSE VCC SENSE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 2,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 2,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 4.4,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 1.5,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					/* FIXME:: Add events */
					
					{},
				},
				.reading2event = {},
			},
			.comment = "BSE Vcc Volt Sensor",
		},
        },
	/* BSE 1.5 Volt Sensor */
        {
		.ipmi_tag = "BSE 1.5V SENSE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 3,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 3,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 4.4,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 1.5,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "0E840402", /* EN_BEM_1_5V_WARNING_HI */
						.event_assertion = SAHPI_TRUE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0E840802", /* EN_BEM_1_5V_WARNING_LOW */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "BSE 1.5 Volt Sensor",
		},
        },
	/* BSE 3.3 Volt Sensor */
        {
		.ipmi_tag = "BSE 3.3V SENSE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 4,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 4,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 3.6,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 3.3,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "0E832402", /* EN_BEM_3_3V_WARNING_HI */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0E832802", /* EN_BEM_3_3V_WARNING_LOW */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "BSE 3.3 Volt Sensor",
		},
        },
	/* BSE 5 Volt Sensor */
        {
		.ipmi_tag = "BSE 5V SENSE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 5,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 5,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 6.7,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 5,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "0E834402", /* EN_BEM_5V_WARNING_HI */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0E834802", /* EN_BEM_5V_WARNING_LOW */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "BSE 5 Volt Sensor",
		},
        },
	/* BSE 12 Volt Sensor */
        {
		.ipmi_tag = "BSE 12V SENSE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 6,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 6,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 16,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 12,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "0E836402", /* EN_BEM_12V_WARNING_HI */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "0E836802", /* EN_BEM_12V_WARNING_LOW */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "BSE 12 Volt Sensor",
		},
        },
	/* PEU2 Temperature Sensor */
        {
		.ipmi_tag = "PEU2 TEMP SENSE",
		.ipmi_tag_alias1 = "PEU2 LOCAL TEMP",
		.ipmi = {
			.index = 7,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 7,
				.Type = SAHPI_TEMPERATURE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_DEGREES_C,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 125,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_UP_MAJOR | SAHPI_STM_UP_CRIT,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpCritical = "discovered",
						.UpMajor    = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.event_array = {
					{
						.event = "FFFFFF26", /* EN_GENERIC_HI_CRIT_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_CRIT,
						.recovery_state = SAHPI_ES_UPPER_MAJOR,
					},
					{
						.event = "FFFFFF27", /* EN_GENERIC_HI_WARN_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "PEU2 Temperature Sensor",
		},
	},
	/* PEU2 1 Volt Sensor */
        {
		.ipmi_tag = "PEU2 1V SENSE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 8,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 8,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 2,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 1,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFF28", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFF29", /* EN_GENERIC_LOWER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "PEU2 1 Volt Sensor",
		},
	},
	/* PEU2 3.3 Volt Sensor */
	{
		.ipmi_tag = "PEU2 3.3V SENSE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 9,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 9,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 3.6,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 3.3,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFF2A", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFF2B", /* EN_GENERIC_LOWER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "PEU2 3.3 Volt Sensor",
		},
	},
	/* PEU2 5 Volt Sensor */
	{
		.ipmi_tag = "PEU2 5V SENSE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 10,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 10,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 6.7,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 5,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFF2C", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFF2D", /* EN_GENERIC_LOWER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "PEU2 5 Volt Sensor",
		},
	},
	/* PEU2 12 Volt Sensor */
	{
		.ipmi_tag = "PEU2 12V SENSE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 11,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 11,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 16,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 12,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFF30", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFF31", /* EN_GENERIC_LOWER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "PEU2 12 Volt Sensor",
		},
	},
	/* PEU2 Standby 12 Volt Sensor */
	{
		.ipmi_tag = "PEU2 12VSB SENSE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 12,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 12,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 16,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 12,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFF32", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFF33", /* EN_GENERIC_LOWER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "PEU2 Standby 12 Volt Sensor",
		},
	},
	/* BIE Temperature Sensor */
        {
		.ipmi_tag = "BIE LOCAL TEMP",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 13,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 13,
				.Type = SAHPI_TEMPERATURE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_DEGREES_C,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 125,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_UP_MAJOR | SAHPI_STM_UP_CRIT,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpCritical = "discovered",
						.UpMajor    = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
				.event_array = {
					{
						.event = "FFFFFF34", /* EN_GENERIC_HI_CRIT_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_CRIT,
						.recovery_state = SAHPI_ES_UPPER_MAJOR,
					},
					{
						.event = "FFFFFF35", /* EN_GENERIC_HI_WARN_TEMP */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "BIE Temperature Sensor",
		},
	},
	/* BIE 1.5 Volt Sensor */
        {
		.ipmi_tag = "BIE 1.5V SENSE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 14,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 14,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 4.4,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 1.5,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFF36", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFF37", /* EN_GENERIC_LOWER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "BIE 1.5 Volt Sensor",
		},
	},
	/* BIE 3.3 Volt Sensor */
	{
		.ipmi_tag = "BIE 3.3V SENSE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 15,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 15,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 3.6,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 3.3,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFF38", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFF39", /* EN_GENERIC_LOWER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "BIE 3.3 Volt Sensor",
		},
	},
	/* BIE 5 Volt Sensor */
	{
		.ipmi_tag = "BIE 5V SENSE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 16,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 16,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 6.7,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 5,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFF3A", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFF3B", /* EN_GENERIC_LOWER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "BIE 5 Volt Sensor",
		},
	},
	/* BIE 12 Volt Sensor */
	{
		.ipmi_tag = "BIE 12V SENSE",
		.ipmi_tag_alias1 = '\0',
		.ipmi = {
			.index = 17,
			.sensor = {
				.Num = SNMP_BC_LAST_NON_IPMI_BEM_SENSOR + 17,
				.Type = SAHPI_VOLTAGE,
				.Category = SAHPI_EC_THRESHOLD,
				.EnableCtrl = SAHPI_FALSE,
				.EventCtrl = SAHPI_SEC_READ_ONLY,
				.Events = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.DataFormat = {
					.IsSupported = SAHPI_TRUE,
					.ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
					.BaseUnits = SAHPI_SU_VOLTS,
					.ModifierUnits = SAHPI_SU_UNSPECIFIED,
					.ModifierUse = SAHPI_SMUU_NONE,
					.Percentage = SAHPI_FALSE,
					.Range = {
						.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN | SAHPI_SRF_NOMINAL,
						.Max = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 16,
							},
						},
						.Nominal = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 12,
							},
						},
						.Min = {
							.IsSupported = SAHPI_TRUE,
							.Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
							.Value = {
								.SensorFloat64 = 0,
							},
						},
					},
				},
				.ThresholdDefn = {
					.IsAccessible = SAHPI_TRUE,
					.ReadThold  = SAHPI_STM_LOW_MAJOR | SAHPI_STM_UP_MAJOR,
					.WriteThold = 0,
				},
				.Oem = 0,
			},
			.sensor_info = {
				.mib = {
					.not_avail_indicator_num = 0,
					.write_only = SAHPI_FALSE,
					.oid = "discovered",
					.loc_offset = 0,
					.threshold_oids = {
						.UpMajor  = "discovered",
						.LowMajor = "discovered",
					},
					.threshold_write_oids = {},
				},
				.cur_state = SAHPI_ES_UNSPECIFIED,
				.sensor_enabled = SAHPI_TRUE,
				.events_enabled = SAHPI_TRUE,
				.assert_mask   = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.deassert_mask = SAHPI_ES_LOWER_MAJOR | SAHPI_ES_UPPER_MAJOR,
				.event_array = {
					{
						.event = "FFFFFF3C", /* EN_GENERIC_UPPER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_UPPER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{
						.event = "FFFFFF3D", /* EN_GENERIC_LOWER_WARN_VOLT */
						.event_assertion = SAHPI_TRUE,
						.event_res_failure = SAHPI_FALSE,
						.event_res_failure_unexpected = SAHPI_FALSE,
						.event_state = SAHPI_ES_LOWER_MAJOR,
						.recovery_state = SAHPI_ES_UNSPECIFIED,
					},
					{},
				},
				.reading2event = {},
			},
			.comment = "BIE 12 Volt Sensor",
		},
	},

        {} /* Terminate array with a null element */
};

/********************
 * Media Tray Sensors
 ********************/

struct snmp_bc_sensor snmp_bc_mediatray_sensors[] = {
        /* Media Tray Operational Status Sensor - event only */
        {
		.index = 1,
                .sensor = {
                        .Num = 1,
                        .Type = SAHPI_OPERATIONAL,
                        .Category = SAHPI_EC_AVAILABILITY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_RUNNING | SAHPI_ES_DEGRADED,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_RUNNING,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_DEGRADED,
			.deassert_mask = SAHPI_ES_DEGRADED,
                        .event_array = {
                                {
                                        .event = "09020000", /* EN_FAULT_FP_R */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "06A2E001", /* EN_FRONT_PANEL_TEMP_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {},
                        },
   			.reading2event = {},
                },
                .comment = "Media Tray Operational Status Sensor",
        },
	/* Media Tray Management Bus Operational Status Sensor - event only */
        {
		.index = 2,
                .sensor = {
                        .Num = 2,
                        .Type = SAHPI_OPERATIONAL,
                        .Category = SAHPI_EC_AVAILABILITY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
			.Events = SAHPI_ES_RUNNING | SAHPI_ES_OFF_LINE,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_RUNNING,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_OFF_LINE,
			.deassert_mask = SAHPI_ES_OFF_LINE,
                        .event_array = {
                                {
                                        .event = "0002205B", /* EN_STCONN_FAIL_MEDIATRAY */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {},
                        },
   			.reading2event = {},
                },
                .comment = "Media Tray Management Bus Operational Status Sensor",
        },

        {} /* Terminate array with a null element */
};

/****************
 * Blower Sensors
 ****************/
struct snmp_bc_sensor snmp_bc_blower_sensors[] = {
        /* Blower Operational Status Sensor */
        {
		.index = 1,
                .sensor = {
                        .Num = 1,
                        .Type = SAHPI_OPERATIONAL,
                        .Category = SAHPI_EC_AVAILABILITY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_RUNNING | SAHPI_ES_OFF_LINE,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
				.ReadingType = SAHPI_SENSOR_READING_TYPE_INT64,
				.BaseUnits = SAHPI_SU_UNSPECIFIED,
				.ModifierUnits = SAHPI_SU_UNSPECIFIED,
				.ModifierUse = SAHPI_SMUU_NONE,
				.Percentage = SAHPI_FALSE,
				.Range = {
					.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
					.Max = {
						.IsSupported = SAHPI_TRUE,
						.Type = SAHPI_SENSOR_READING_TYPE_INT64,
						.Value = {
							.SensorInt64 = 3,
						},
					},
					.Min = {
						.IsSupported = SAHPI_TRUE,
						.Type = SAHPI_SENSOR_READING_TYPE_INT64,
						.Value = {
							.SensorInt64 = 0,
						},
					},
				},
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.3.x.0",
				.loc_offset = (10 - 1),
                        },
                        .cur_state = SAHPI_ES_RUNNING,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_OFF_LINE,
			.deassert_mask = SAHPI_ES_OFF_LINE,
                        .event_array = {
                                {
                                        .event = "0002680x", /* EN_FAN1_SPEED */
  					.event_assertion = SAHPI_TRUE,
                                        .event_state = SAHPI_ES_OFF_LINE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0B02600x", /* EN_UNREC_FANx */
  					.event_assertion = SAHPI_TRUE,
                                        .event_state = SAHPI_ES_OFF_LINE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {},
                        },
   			.reading2event = {
				/* 0 = unknown */
				{
					.num = 1,
                                        .rangemap = {
						.Flags = SAHPI_SRF_MIN,
						.Min = {
							.Value = {
								.SensorInt64 = 1,
							},
						},
					},
					.state = SAHPI_ES_UNSPECIFIED,
                                },
				/* 1 = good */
				{
					.num = 2,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorInt64 = 1, 
							},
						},
					},
					.state = SAHPI_ES_RUNNING,
				},
				/* 2 = warning */
 				{
					.num = 3,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorInt64 = 2,
							},
						},
					},
					.state = SAHPI_ES_DEGRADED,
                                },
				/* 3 = bad */
 				{
					.num = 4,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorInt64 = 3,
							},
						},
					},
					.state = SAHPI_ES_OFF_LINE,
                                },
			},
                },
                .comment = "Blower Operational Status Sensor",
        },
        /* Blower Speed (Percent of Max) Sensor */
        {
		.index = 2,
                .sensor = {
                        .Num = 2,
                        .Type = SAHPI_FAN,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_UPPER_MAJOR,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_RPM,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_TRUE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
                                        .Max = {
  						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 100,
                                                },
                                        },
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
			.ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                                .ReadThold = 0,
				.WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.3.x.0",
				.loc_offset = 0,
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_UPPER_MAJOR,
			.deassert_mask = SAHPI_ES_UPPER_MAJOR,
                        .event_array = {
                                {
                                        .event = "000A600x", /* EN_FAN1_PFA */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
   			.reading2event = {},
                },
                .comment = "Blower Speed (Percent of Max) Sensor",
        },
	/* Blower Management Bus Operational Status Sensor - event only */
        {
		.index = 3,
                .sensor = {
                        .Num = 3,
                        .Type = SAHPI_OPERATIONAL,
                        .Category = SAHPI_EC_AVAILABILITY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
			.Events = SAHPI_ES_RUNNING | SAHPI_ES_OFF_LINE,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_RUNNING,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_OFF_LINE,
			.deassert_mask = SAHPI_ES_OFF_LINE,
                        .event_array = {
                                {
                                        .event = "000A200x", /* EN_STCONN_FAIL_BLOWER_x */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {},
                        },
   			.reading2event = {},
                },
                .comment = "Blower Management Bus Operational Status Sensor",
        },

        {} /* Terminate array with a null element */
};

/* BladeCenter H specific blower sensors */
#define SNMP_BC_LAST_COMMON_BLOWER_SENSOR 3
struct snmp_bc_sensor snmp_bc_blower_sensors_bch[] = {
        /* Blower RPM Speed Sensor */
        {
		.index = 1,
                .sensor = {
                        .Num = SNMP_BC_LAST_COMMON_BLOWER_SENSOR + 1,
                        .Type = SAHPI_FAN,
                        .Category = SAHPI_EC_UNSPECIFIED,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = 0x00,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_RPM,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
                                        .Max = {
  						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 4000,
                                                },
                                        },
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
			.ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.3.x.0",
				.loc_offset = (20 - 1),
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = 0x00,
			.deassert_mask = 0x00,
                        .event_array = {
                                {},
                        },
   			.reading2event = {},
                },
                .comment = "Blower RPM Speed Sensor",
        },

        {} /* Terminate array with a null element */
};

/***************
 * Power Sensors
 ***************/

struct snmp_bc_sensor snmp_bc_power_sensors[] = {
        /* Power Module Operational Status Sensor */
        {
		.index = 1,
                .sensor = {
                        .Num = 1,
                        .Type = SAHPI_OPERATIONAL,
                        .Category = SAHPI_EC_AVAILABILITY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
			.Events = SAHPI_ES_RUNNING | SAHPI_ES_DEGRADED | SAHPI_ES_OFF_LINE,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
				.ReadingType = SAHPI_SENSOR_READING_TYPE_INT64,
				.BaseUnits = SAHPI_SU_UNSPECIFIED,
				.ModifierUnits = SAHPI_SU_UNSPECIFIED,
				.ModifierUse = SAHPI_SMUU_NONE,
				.Percentage = SAHPI_FALSE,
				.Range = {
					.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
					.Max = {
						.IsSupported = SAHPI_TRUE,
						.Type = SAHPI_SENSOR_READING_TYPE_INT64,
						.Value = {
							.SensorInt64 = 3,
						},
					},
					.Min = {
						.IsSupported = SAHPI_TRUE,
						.Type = SAHPI_SENSOR_READING_TYPE_INT64,
						.Value = {
							.SensorInt64 = 0,
						},
					},
				},
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.4.1.1.3.x",
				.loc_offset = 0,
                        },
                        .cur_state = SAHPI_ES_RUNNING,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_DEGRADED | SAHPI_ES_OFF_LINE,
			.deassert_mask = SAHPI_ES_DEGRADED | SAHPI_ES_OFF_LINE,
                        .event_array = {
                                {
                                        .event = "0820000x", /* EN_FAULT_PSx */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0823600x", /* EN_FAULT_PSx_12V_OVR_CUR */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0802800x", /* EN_FAULT_PSx_DC_GOOD */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0823648x", /* EN_FAULT_PSx_12V_OVER */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0823680x", /* EN_FAULT_PSx_12V_UNDER */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0818000x", /* EN_FAULT_PSx_EPOW */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0821A00x", /* EN_FAULT_PSx_CUR_FAIL */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {},
                        },
   			.reading2event = {
				/* 0 = unknown */
				{
					.num = 1,
                                        .rangemap = {
						.Flags = SAHPI_SRF_MIN,
						.Min = {
							.Value = {
								.SensorInt64 = 1,
							},
						},
					},
					.state = SAHPI_ES_UNSPECIFIED,
                                },
				/* 1 = good */
				{
					.num = 2,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorInt64 = 1, 
							},
						},
					},
					.state = SAHPI_ES_RUNNING,
				},
				/* 2 = warning */
 				{
					.num = 3,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorInt64 = 2,
							},
						},
					},
					.state = SAHPI_ES_DEGRADED,
                                },
				/* 3 = bad */
 				{
					.num = 4,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorInt64 = 3,
							},
						},
					},
					.state = SAHPI_ES_OFF_LINE,
                                },
			},
                },
                .comment = "Power Module Operational Status Sensor",
        },
        /* Power Module Temperature Sensor - event-only */
        {
		.index = 2,
                .sensor = {
                        .Num = 2,
                        .Type = SAHPI_TEMPERATURE,
                        .Category = SAHPI_EC_THRESHOLD,
 			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
			.DataFormat = {
				.IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                                .ReadThold = 0,
				.WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
			.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
                        .event_array = {
                                {
                                        .event = "0821C08x", /* EN_FAULT_PSx_OVR_TEMP */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UPPER_MAJOR,
                                },
                                {
                                        .event = "0821C00x", /* EN_FAULT_PS1_TEMP_WARN */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
   			.reading2event = {},
                },
                .comment = "Power Module Temperature Sensor",
        },
	/* Power Module Management Bus Operational Status Sensor - event only */
        {
		.index = 3,
                .sensor = {
                        .Num = 3,
                        .Type = SAHPI_OPERATIONAL,
                        .Category = SAHPI_EC_AVAILABILITY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
			.Events = SAHPI_ES_RUNNING | SAHPI_ES_OFF_LINE,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_RUNNING,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_OFF_LINE,
			.deassert_mask = SAHPI_ES_OFF_LINE,
                        .event_array = {
                                {
                                        .event = "0822200x", /* EN_STCONN_FAIL_POWER_x */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {},
                        },
   			.reading2event = {},
                },
                .comment = "Power Module Management Bus Operational Status Sensor",
        },

        {} /* Terminate array with a null element */
};

#define SNMP_BC_LAST_COMMON_POWER_MODULE_SENSOR 3

/* BladeCenter H specific power module sensors */
struct snmp_bc_sensor snmp_bc_power_sensors_bch[] = {
        /* Power Module Fan Pack Operational Status Sensor */
        {
		.index = 1,
                .sensor = {
                        .Num = SNMP_BC_LAST_COMMON_POWER_MODULE_SENSOR + 1,
                        .Type = SAHPI_OPERATIONAL,
                        .Category = SAHPI_EC_AVAILABILITY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
			.Events = SAHPI_ES_RUNNING | SAHPI_ES_OFF_LINE,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
				.ReadingType = SAHPI_SENSOR_READING_TYPE_INT64,
				.BaseUnits = SAHPI_SU_UNSPECIFIED,
				.ModifierUnits = SAHPI_SU_UNSPECIFIED,
				.ModifierUse = SAHPI_SMUU_NONE,
				.Percentage = SAHPI_FALSE,
				.Range = {
					.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
					.Max = {
						.IsSupported = SAHPI_TRUE,
						.Type = SAHPI_SENSOR_READING_TYPE_INT64,
						.Value = {
							.SensorInt64 = 3,
						},
					},
					.Min = {
						.IsSupported = SAHPI_TRUE,
						.Type = SAHPI_SENSOR_READING_TYPE_INT64,
						.Value = {
							.SensorInt64 = 0,
						},
					},
				},
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.6.1.1.3.x",
				.loc_offset = 0,
                        },
                        .cur_state = SAHPI_ES_RUNNING,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_OFF_LINE,
			.deassert_mask = SAHPI_ES_OFF_LINE,
                        .event_array = {
                                {
                                        .event = "0003680x", /* EN_FAN_PACKx_SPEED */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "000A7001", /* EN_FAN_PACK1_NOT_PRESENT */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {},
                        },
   			.reading2event = {
				/* 0 = unknown */
				{
					.num = 1,
                                        .rangemap = {
						.Flags = SAHPI_SRF_MIN,
						.Min = {
							.Value = {
								.SensorInt64 = 1,
							},
						},
					},
					.state = SAHPI_ES_UNSPECIFIED,
                                },
				/* 1 = good */
				{
					.num = 2,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorInt64 = 1, 
							},
						},
					},
					.state = SAHPI_ES_RUNNING,
				},
				/* 2 = warning */
 				{
					.num = 3,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorInt64 = 2,
							},
						},
					},
					.state = SAHPI_ES_DEGRADED,
                                },
				/* 3 = bad */
 				{
					.num = 4,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorInt64 = 3,
							},
						},
					},
					.state = SAHPI_ES_OFF_LINE,
                                },
			},
                },
                .comment = "Power Module Fan Pack Operational Status Sensor",
        },
        /* Power Module Fan Pack Average Speed (Percent of Max) Sensor */
        {
		.index = 2,
                .sensor = {
                        .Num = SNMP_BC_LAST_COMMON_POWER_MODULE_SENSOR + 2,
                        .Type = SAHPI_FAN,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_UPPER_MAJOR,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_RPM,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_TRUE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
                                        .Max = {
  						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 100,
                                                },
                                        },
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
			.ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                                .ReadThold = 0,
				.WriteThold = 0,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.6.1.1.5.x",
				.loc_offset = 0,
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_UPPER_MAJOR,
			.deassert_mask = SAHPI_ES_UPPER_MAJOR,
                        .event_array = {
                                {
                                        .event = "000B600x", /* EN_FAN_PACKx_PFA */
 					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_UPPER_MAJOR,
                                        .recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
   			.reading2event = {},
                },
                .comment = "Power Module Fan Pack Average Speed (Percent of Max) Sensor",
        },
        /* Power Module Fan Pack Average RPM Speed Sensor */
        {
		.index = 3,
                .sensor = {
                        .Num = SNMP_BC_LAST_COMMON_POWER_MODULE_SENSOR + 3,
                        .Type = SAHPI_FAN,
                        .Category = SAHPI_EC_UNSPECIFIED,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = 0x00,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_FLOAT64,
                                .BaseUnits = SAHPI_SU_RPM,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
                                        .Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
                                        .Max = {
  						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 13000,
                                                },
                                        },
                                        .Min = {
						.IsSupported = SAHPI_TRUE,
                                                .Type = SAHPI_SENSOR_READING_TYPE_FLOAT64,
						.Value = {
							.SensorFloat64 = 0,
                                                },
                                        },
                                },
                        },
			.ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.6.1.1.6.x",
				.loc_offset = 0,
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = 0x00,
			.deassert_mask = 0x00,
                        .event_array = {
                                {},
                        },
   			.reading2event = {},
                },
                .comment = "Power Module Fan Pack Average RPM Speed Sensor",
        },

        {} /* Terminate array with a null element */
};

/********************
 * I/O Module Sensors
 ********************/

struct snmp_bc_sensor snmp_bc_switch_sensors[] = {
        /* I/O Module Operational Status Sensor */
        {
		.index = 1,
                .sensor = {
                        .Num = 1,
                        .Type = SAHPI_OPERATIONAL,
                        .Category = SAHPI_EC_AVAILABILITY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = SAHPI_ES_RUNNING | SAHPI_ES_OFF_LINE | 
			          SAHPI_ES_DEGRADED | SAHPI_ES_INSTALL_ERROR,
                        .DataFormat = {
				.IsSupported = SAHPI_TRUE,
				.ReadingType = SAHPI_SENSOR_READING_TYPE_INT64,
				.BaseUnits = SAHPI_SU_UNSPECIFIED,
				.ModifierUnits = SAHPI_SU_UNSPECIFIED,
				.ModifierUse = SAHPI_SMUU_NONE,
				.Percentage = SAHPI_FALSE,
				.Range = {
					.Flags = SAHPI_SRF_MAX | SAHPI_SRF_MIN,
					.Max = {
						.IsSupported = SAHPI_TRUE,
						.Type = SAHPI_SENSOR_READING_TYPE_INT64,
						.Value = {
							.SensorInt64 = 3,
						},
					},
					.Min = {
						.IsSupported = SAHPI_TRUE,
						.Type = SAHPI_SENSOR_READING_TYPE_INT64,
						.Value = {
							.SensorInt64 = 0,
						},
					},
				},
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.3.1.1.1.15.x",
				.loc_offset = 0,
                        },
                        .cur_state = SAHPI_ES_RUNNING,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_DEGRADED | SAHPI_ES_OFF_LINE | SAHPI_ES_INSTALL_ERROR,
			.deassert_mask = SAHPI_ES_DEGRADED | SAHPI_ES_OFF_LINE | SAHPI_ES_INSTALL_ERROR,
                        .event_array = {
                                {
                                        .event = "0EA0000x", /* EN_FAULT_SWITCH_x */
					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0E00B00x", /* EN_SWITCH_x_INSUFFICIENT_PWR */
   					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
				{
                                        .event = "0EA0C00x", /* EN_SWITCH_x_CFG_ERROR */
   					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_INSTALL_ERROR,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0EA0E00x", /* EN_SWITCH_x_POST_ERROR */
   					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
					.event_state = SAHPI_ES_INSTALL_ERROR,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0EA0D00x", /* EN_SWITCH_x_POST_TIMEOUT */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_INSTALL_ERROR,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {
                                        .event = "0EA1A40x", /* EN_OVER_CURRENT_SWITCH_x */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_DEGRADED,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {},
                        },
   			.reading2event = {
				/* 0 = unknown */
				{
					.num = 1,
                                        .rangemap = {
						.Flags = SAHPI_SRF_MIN,
						.Min = {
							.Value = {
								.SensorInt64 = 1,
							},
						},
					},
					.state = SAHPI_ES_UNSPECIFIED,
                                },
				/* 1 = good */
				{
					.num = 2,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorInt64 = 1, 
							},
						},
					},
					.state = SAHPI_ES_RUNNING,
				},
				/* 2 = warning */
 				{
					.num = 3,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorInt64 = 2,
							},
						},
					},
					.state = SAHPI_ES_DEGRADED,
                                },
				/* 3 = bad */
 				{
					.num = 4,
                                        .rangemap = {
						.Flags = SAHPI_SRF_NOMINAL,
						.Nominal = {
							.Value = {
								.SensorInt64 = 3,
							},
						},
					},
					.state = SAHPI_ES_OFF_LINE,
                                },
			},
                },
                .comment = "I/O Module Operational Status Sensor",
        },
        /* I/O Module Temperature Sensor - event-only */
        {
		.index = 2,
                .sensor = {
                        .Num = 2,
                        .Type = SAHPI_TEMPERATURE,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
			.Events = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
			.DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
				.ReadThold = 0,
				.WriteThold = 0,
                       },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
			.deassert_mask = SAHPI_ES_UPPER_MAJOR | SAHPI_ES_UPPER_CRIT,
                        .event_array = {
                                {
                                        .event = "0EA1C40x", /* EN_OVER_TEMP_SWITCH_x */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_CRIT,
                                        .recovery_state = SAHPI_ES_UPPER_MAJOR,
                                },
                                {
                                        .event = "0EA1D40x", /* EN_OVER_TEMP_WARN_SWITCH_x */
  					.event_assertion = SAHPI_TRUE,
					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_UPPER_MAJOR,
					.recovery_state = SAHPI_ES_UNSPECIFIED,
                                },
                                {},
                        },
   			.reading2event = {},
                },
                .comment = "I/O Module Temperature Sensor",
        },
	/* I/O Module Management Bus Operational Status  Sensor - event only */
        {
		.index = 3,
                .sensor = {
                        .Num = 3,
                        .Type = SAHPI_OPERATIONAL,
                        .Category = SAHPI_EC_AVAILABILITY,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
			.Events = SAHPI_ES_RUNNING | SAHPI_ES_OFF_LINE,
                        .DataFormat = {
                                .IsSupported = SAHPI_FALSE,
                        },
                        .ThresholdDefn = {
                                .IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .cur_state = SAHPI_ES_RUNNING,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_TRUE,
			.assert_mask   = SAHPI_ES_OFF_LINE,
			.deassert_mask = SAHPI_ES_OFF_LINE,
                        .event_array = {
                                {
                                        .event = "0EA2200x", /* EN_STCONN_FAIL_SWITCH_x */
  					.event_assertion = SAHPI_TRUE,
       					.event_res_failure = SAHPI_FALSE,
					.event_res_failure_unexpected = SAHPI_FALSE,
                                        .event_state = SAHPI_ES_OFF_LINE,
                                        .recovery_state = SAHPI_ES_RUNNING,
                                },
                                {},
                        },
   			.reading2event = {},
                },
                .comment = "I/O Module Management Bus 0perations Sensor",
        },

        {} /* Terminate array with a null element */
};

/***********************************
 * BladeCenter Physical Slot Sensors
 ***********************************/

struct snmp_bc_sensor snmp_bc_slot_sensors[] = {
        {
		.index = 1,
                .sensor = {
                        .Num = BLADECENTER_SENSOR_NUM_SLOT_STATE,
                        .Type = SAHPI_ENTITY_PRESENCE,
                        .Category = SAHPI_EC_PRESENCE,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY |
				     SAHPI_SEC_READ_ONLY_MASKS |
				     SAHPI_SEC_PER_EVENT,
                        .Events = SAHPI_ES_PRESENT | SAHPI_ES_ABSENT, 
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_UINT64,
                                .BaseUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
                                .Range = {
					.Flags = 0x00,
				} 
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
                .sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,          
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.10.2.1.1.8.1", /* Dummy OID to bypass test */
				.loc_offset = 0,
                        },
                        .cur_state = SAHPI_ES_ABSENT,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_FALSE,
                        .assert_mask   = 0,
                        .deassert_mask = 0,
                        .event_array = {
                                {},
			},
                        .reading2event = {},
                },
                .comment = "Slot State Sensor",
        },
	/* Slot Maximum Power Capability Sensor */
	{
		.index = 2,
                .sensor = {
                        .Num = BLADECENTER_SENSOR_NUM_MAX_POWER,
                        .Type = SAHPI_OTHER_UNITS_BASED_SENSOR,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = 0x00,				/* No event state */
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_UINT64,
                                .BaseUnits = SAHPI_SU_WATTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
				.Range = {
                                        .Flags = 0x00,
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_FALSE,
                        },
                        .Oem = 0,
                },
		.sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.10.2.1.1.8.1",
				.loc_offset = 0,
                                .threshold_oids = {},
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_FALSE,
			.assert_mask   = 0x00,
			.deassert_mask = 0x00,
			.event_array = {
                                {},
                        },
		        .reading2event = {},
                },
		.comment = "Slot Maximum Power Capability Sensor",
	},
	/* Slot Assigned Power Sensor */
	{
		.index = 3,
                .sensor = {
                        .Num = BLADECENTER_SENSOR_NUM_ASSIGNED_POWER,
                        .Type = SAHPI_OTHER_UNITS_BASED_SENSOR,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = 0,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_UINT64,
                                .BaseUnits = SAHPI_SU_WATTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
				.Range = {
                                        .Flags = 0x00,
                                },
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_FALSE,
                                .ReadThold = 0,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
		.sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.10.2.1.1.7.1",
				.loc_offset = 0,
                                .threshold_oids = {},			
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_FALSE,
			.assert_mask   = 0x00,
			.deassert_mask = 0x00,
			.event_array = {
                                {},
                        },
		        .reading2event = {},
                },
		.comment = "Slot Assigned Power Sensor",
	},
	/* Slot Minumum Power Capability Sensor */
	{
		.index = 4,
                .sensor = {
                        .Num = BLADECENTER_SENSOR_NUM_MIN_POWER,
                        .Type = SAHPI_OTHER_UNITS_BASED_SENSOR,
                        .Category = SAHPI_EC_THRESHOLD,
			.EnableCtrl = SAHPI_FALSE,
                        .EventCtrl = SAHPI_SEC_READ_ONLY,
                        .Events = 0,
                        .DataFormat = {
                                .IsSupported = SAHPI_TRUE,
                                .ReadingType = SAHPI_SENSOR_READING_TYPE_UINT64,
                                .BaseUnits = SAHPI_SU_WATTS,
                                .ModifierUnits = SAHPI_SU_UNSPECIFIED,
                                .ModifierUse = SAHPI_SMUU_NONE,
                                .Percentage = SAHPI_FALSE,
				.Range = {},
                        },
                        .ThresholdDefn = {
				.IsAccessible = SAHPI_FALSE,
                                .ReadThold = 0,
                                .WriteThold = 0,
                        },
                        .Oem = 0,
                },
		.sensor_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.10.2.1.1.9.1",
				.loc_offset = 0,
                                .threshold_oids = {},
				.threshold_write_oids = {},
                        },
                        .cur_state = SAHPI_ES_UNSPECIFIED,
			.cur_child_rid = SAHPI_UNSPECIFIED_RESOURCE_ID,
                        .sensor_enabled = SAHPI_TRUE,
                        .events_enabled = SAHPI_FALSE,
			.assert_mask   = 0,
			.deassert_mask = 0,
			.event_array = {
                                {},
                        },
		        .reading2event = {},
                },
		.comment = "Slot Minumum Power Capability Sensor",
	},

        {} /* Terminate array with a null element */
};

/*************************************************************************
 *                   Control Definitions
 *************************************************************************/

/*************************************************************************
 * WARNING  -   WARNING  - WARNING  -  WARNING 
 * Most of the .control.num are assigned sequentially.   
 * There is 1 hardcoded control number:
 *        BLADECENTER_CTRL_NUM_MGMNT_FAILOVER 
 *************************************************************************/
 
/******************
 * Chassis Controls
 ******************/

struct snmp_bc_control snmp_bc_chassis_controls_bc[] = {
        /* Chassis Location LED */
  	/* 0 is Off; 1 is solid on; 2 is blinking */
	{
		.index = 1,
                .control = {
                        .Num = 1,
                        .OutputType = SAHPI_CTRL_LED,
                        .Type = SAHPI_CTRL_TYPE_DISCRETE,
                        .TypeUnion.Discrete.Default = 0,
			.DefaultMode = {
				.Mode = SAHPI_CTRL_MODE_MANUAL,
				.ReadOnly = SAHPI_TRUE,
			},
			.WriteOnly = SAHPI_FALSE,
                        .Oem = 0,
                },
                .control_info = {
                        .mib = {
                                .not_avail_indicator_num = 3,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.8.1.4.0",
				.loc_offset = 0,
                        },
			.cur_mode = SAHPI_CTRL_MODE_MANUAL,
                },
                .comment = "Chassis Location LED",
        },

        {} /* Terminate array with a null element */
};

struct snmp_bc_control snmp_bc_chassis_controls_bct[] = {
        /* Chassis Location LED */
  	/* 0 is Off; 1 is solid on; 2 is blinking */
	{
		.index = 1,
                .control = {
                        .Num = 1,
                        .OutputType = SAHPI_CTRL_LED,
                        .Type = SAHPI_CTRL_TYPE_DISCRETE,
                        .TypeUnion.Discrete.Default = 0,
			.DefaultMode = {
				.Mode = SAHPI_CTRL_MODE_MANUAL,
				.ReadOnly = SAHPI_TRUE,
			},
			.WriteOnly = SAHPI_FALSE,
                        .Oem = 0,
                },
                .control_info = {
                        .mib = {
                                .not_avail_indicator_num = 3,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.8.3.4.0",
				.loc_offset = 0,
                        },
			.cur_mode = SAHPI_CTRL_MODE_MANUAL,
                },
                .comment = "Chassis Location LED",
        },

        {} /* Terminate array with a null element */
};

/****************
 * Blade Controls
 ****************/

struct snmp_bc_control snmp_bc_blade_controls[] = {
        /* Blade Location LED */
	/* 0 is Off; 1 is solid on; 2 is blinking */
        {
		.index = 1,
                .control = {
                        .Num = 1,
                        .OutputType = SAHPI_CTRL_LED,
                        .Type = SAHPI_CTRL_TYPE_DISCRETE,
                        .TypeUnion.Discrete.Default = 0,
 			.DefaultMode = {
				.Mode = SAHPI_CTRL_MODE_MANUAL,
				.ReadOnly = SAHPI_TRUE,
			},
			.WriteOnly = SAHPI_FALSE,
                       .Oem = 0,
                },
                .control_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.2.8.2.1.1.11.x",
				.loc_offset = 0,
                        },
 			.cur_mode = SAHPI_CTRL_MODE_MANUAL,
               },
                .comment = "Blade Location LED",
        },
	/* Blade BMC Reset */
	/* 1 = reset */
        {
		.index = 2,
                .control = {
                        .Num = 2,
                        .OutputType = SAHPI_CTRL_GENERIC,
                        .Type = SAHPI_CTRL_TYPE_DISCRETE,
                        .TypeUnion.Discrete.Default = 1,
 			.DefaultMode = {
				.Mode = SAHPI_CTRL_MODE_MANUAL,
				.ReadOnly = SAHPI_TRUE,
			},
			.WriteOnly = SAHPI_TRUE,
                       .Oem = 0,
                },
                .control_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .oid = ".1.3.6.1.4.1.2.3.51.2.22.1.6.1.1.9.x",
				.loc_offset = 0,
                        },
 			.cur_mode = SAHPI_CTRL_MODE_MANUAL,
               },
                .comment = "Blade BMC Reset",
        },

        {} /* Terminate array with a null element */
};

/***************************************
 * Blade Expansion Module (BEM) Controls
 ***************************************/

struct snmp_bc_control snmp_bc_bem_controls[] = {

        {} /* Terminate array with a null element */
};

/************************************
 * Virtual Management Module Controls
 ************************************/

struct snmp_bc_control snmp_bc_virtual_mgmnt_controls[] = {
	/* MM Failover Control */
	{
		.index = 1,
		.control = {
			.Num = BLADECENTER_CTRL_NUM_MGMNT_FAILOVER,
			.OutputType = SAHPI_CTRL_GENERIC,
			.Type = SAHPI_CTRL_TYPE_DIGITAL,
			.TypeUnion.Digital.Default = SAHPI_CTRL_STATE_OFF,
			.DefaultMode = {
				.Mode = SAHPI_CTRL_MODE_MANUAL,
				.ReadOnly = SAHPI_TRUE,
			},
			.WriteOnly = SAHPI_FALSE,
			.Oem = 0,
		},
		.control_info = {
			.mib = {
				.not_avail_indicator_num = 0,
				.write_only = SAHPI_FALSE,
				.oid = ".1.3.6.1.4.1.2.3.51.2.7.7.0",
				.loc_offset = 0,
				/* Read values */
				.digitalmap[0] = -1, /* Always return SAHPI_CTRL_STATE_OFF */
				.digitalmap[1] = -1, /* Always return SAHPI_CTRL_STATE_OFF */
				.digitalmap[2] = -1, /* Always return SAHPI_CTRL_STATE_OFF */
				.digitalmap[3] = -1, /* Always return SAHPI_CTRL_STATE_OFF */
				/* Write values */
				.digitalwmap[0] = -1, /* SAHPI_CTRL_STATE_OFF - Invalid */
				.digitalwmap[1] = -1, /* SAHPI_CTRL_STATE_ON - Invalid */
				.digitalwmap[2] = -1, /* SAHPI_CTRL_STATE_PULSE_OF - Invalid */
				.digitalwmap[3] = 1,  /* SAHPI_CTRL_STATE_PULSE_ON */
				/* Constant read state */
				.isDigitalReadStateConstant = SAHPI_TRUE,
				.DigitalStateConstantValue = SAHPI_CTRL_STATE_OFF,
			},
			.cur_mode = SAHPI_CTRL_MODE_MANUAL,
		},
		.comment = "MM Failover Control",
	},

        {} /* Terminate array with a null element */
};

/****************************
 * Management Module Controls
 ****************************/

struct snmp_bc_control snmp_bc_mgmnt_controls[] = {

        {} /* Terminate array with a null element */
};

/*********************
 * Media Tray Controls
 *********************/

struct snmp_bc_control snmp_bc_mediatray_controls[] = {

        {} /* Terminate array with a null element */
};

/*****************
 * Blower Controls
 *****************/

struct snmp_bc_control snmp_bc_blower_controls[] = {

        {} /* Terminate array with a null element */
};

/****************
 * Power Controls
 ****************/

struct snmp_bc_control snmp_bc_power_controls[] = {

        {} /* Terminate array with a null element */
};

/************************
 * Switch Module Controls
 ************************/

struct snmp_bc_control snmp_bc_switch_controls[] = {

        {} /* Terminate array with a null element */
};


/***********************
 * Physical Slot Controls
 ***********************/

struct snmp_bc_control snmp_bc_slot_controls[] = {

        {} /* Terminate array with a null element */
};

/*************************************************************************
 *                   Inventory Definitions
 *************************************************************************/

/*************
 * Chassis VPD
 *************/

struct snmp_bc_inventory snmp_bc_chassis_inventories[] = {
        {
                .inventory = {
                        .IdrId = 1,
                        .Oem = 0,
                },
                .inventory_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .area_type = SAHPI_IDR_AREATYPE_CHASSIS_INFO,
                                .oid = {
                                        .OidChassisType = ".1.3.6.1.4.1.2.3.51.2.2.21.1.1.2.0",
                                        .OidMfgDateTime = '\0',   /* Set to SAHPI_TIME_UNSPECIFIED */
                                        .OidManufacturer = ".1.3.6.1.4.1.2.3.51.2.2.21.1.1.5.0",
                                        .OidProductName = ".1.3.6.1.4.1.2.3.51.2.2.21.1.1.1.0",
                                        .OidProductVersion = ".1.3.6.1.4.1.2.3.51.2.2.21.1.1.6.0",
                                        .OidSerialNumber = ".1.3.6.1.4.1.2.3.51.2.2.21.1.1.3.0",
                                        .OidPartNumber = ".1.3.6.1.4.1.2.3.51.2.2.21.1.1.7.0",
                                        .OidFileId = '\0',
                                        .OidAssetTag = '\0',
                                }
                        },
                },
                .comment = "Chassis VPD",
        },

        {} /* Terminate array with a null element */
};

/************
 * Blower VPD
 ************/

struct snmp_bc_inventory snmp_bc_blower_inventories[] = {

        {} /* Terminate array with a null element */
};

/*******************************
 * Virtual Management Module VPD
 *******************************/

struct snmp_bc_inventory snmp_bc_virtual_mgmnt_inventories[] = {

        {} /* Terminate array with a null element */
};

/***********************
 * Management Module VPD
 ***********************/

struct snmp_bc_inventory snmp_bc_mgmnt_inventories[] = {
        {
                .inventory = {
                        .IdrId = 4,
                        .Oem = 0,
                },
                .inventory_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .area_type = SAHPI_IDR_AREATYPE_BOARD_INFO,
                                .oid = {
                                        .OidChassisType = '\0',
                                        .OidMfgDateTime = '\0',   /* Set to SAHPI_TIME_UNSPECIFIED */
                                        .OidManufacturer = ".1.3.6.1.4.1.2.3.51.2.2.21.2.1.1.3.x",
                                        .OidProductName = '\0',
                                        .OidProductVersion = ".1.3.6.1.4.1.2.3.51.2.2.21.2.1.1.5.x",
                                        .OidSerialNumber = '\0',
                                        .OidPartNumber = ".1.3.6.1.4.1.2.3.51.2.2.21.2.1.1.4.x",
                                        .OidFileId = '\0',
                                        .OidAssetTag = '\0',
                                }
                        },
                },
                .comment = "MM VPD",
        },

        {} /* Terminate array with a null element */
};

/****************
 * I/O Module VPD
 ****************/

struct snmp_bc_inventory snmp_bc_switch_inventories[] = {
        {
                .inventory = {
                        .IdrId = 5,
                        .Oem = 0,
                },
                .inventory_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .area_type = SAHPI_IDR_AREATYPE_BOARD_INFO,
                                .oid = {
                                        .OidChassisType = '\0',
                                        .OidMfgDateTime = '\0',   /* Set to SAHPI_TIME_UNSPECIFIED */
                                        .OidManufacturer = ".1.3.6.1.4.1.2.3.51.2.2.21.6.1.1.3.x",
                                        .OidProductName = '\0',
                                        .OidProductVersion = ".1.3.6.1.4.1.2.3.51.2.2.21.6.1.1.5.x",
                                        .OidSerialNumber = '\0',
                                        .OidPartNumber = ".1.3.6.1.4.1.2.3.51.2.2.21.6.1.1.4.x",
                                        .OidFileId = '\0',
                                        .OidAssetTag = '\0',
                                }
                        },
                },
                .comment = "I/O Module VPD",
        },

        {} /* Terminate array with a null element */
};

/***********
 * Blade VPD
 ***********/

struct snmp_bc_inventory snmp_bc_blade_inventories[] = {
        {
                .inventory = {
                        .IdrId = 6,
                        .Oem = 0,
                },
                .inventory_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .area_type = SAHPI_IDR_AREATYPE_BOARD_INFO,
                                .oid = {
                                        .OidChassisType = '\0',
                                        .OidMfgDateTime = '\0',   /* Set to SAHPI_TIME_UNSPECIFIED */
                                        .OidManufacturer = ".1.3.6.1.4.1.2.3.51.2.2.21.4.1.1.3.x",
                                        .OidProductName = ".1.3.6.1.4.1.2.3.51.2.2.21.4.1.1.7.x",
                                        .OidProductVersion = ".1.3.6.1.4.1.2.3.51.2.2.21.4.1.1.5.x",
                                        .OidSerialNumber = ".1.3.6.1.4.1.2.3.51.2.2.21.4.1.1.6.x",
                                        .OidPartNumber = ".1.3.6.1.4.1.2.3.51.2.2.21.4.1.1.4.x",
                                        .OidFileId = '\0',
                                        .OidAssetTag = '\0',
                                }
                        },
                },
                .comment = "Blade VPD",
        },

        {} /* Terminate array with a null element */
};

/**********************************
 * Blade Expansion Module (BEM) VPD
 **********************************/

struct snmp_bc_inventory snmp_bc_bem_inventories[] = {

        {} /* Terminate array with a null element */
};

/****************
 * Media Tray VPD
 ****************/

struct snmp_bc_inventory snmp_bc_mediatray_inventories[] = {
        {
                .inventory = {
                        .IdrId = 8,
                        .Oem = 0,
                },
                .inventory_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .area_type = SAHPI_IDR_AREATYPE_BOARD_INFO,
                                .oid = {
                                        .OidChassisType = '\0',
                                        .OidMfgDateTime = '\0',   /* Set to SAHPI_TIME_UNSPECIFIED */
                                        .OidManufacturer = ".1.3.6.1.4.1.2.3.51.2.2.21.9.3.0",
                                        .OidProductName = '\0',
                                        .OidProductVersion = ".1.3.6.1.4.1.2.3.51.2.2.21.9.5.0",
                                        .OidSerialNumber = '\0',
                                        .OidPartNumber = ".1.3.6.1.4.1.2.3.51.2.2.21.9.4.0",
                                        .OidFileId = '\0',
                                        .OidAssetTag = '\0',
                                }
                        },
                },
                .comment = "Media Tray VPD",
        },

        {} /* Terminate array with a null element */
};

/******************
 * Power Module VPD
 ******************/

struct snmp_bc_inventory snmp_bc_power_inventories[] = {
        {
                .inventory = {
                        .IdrId = 9,
                        .Oem = 0,
                },
                .inventory_info = {
                        .mib = {
                                .not_avail_indicator_num = 0,
                                .write_only = SAHPI_FALSE,
                                .area_type = SAHPI_IDR_AREATYPE_BOARD_INFO,
                                .oid = {
                                        .OidChassisType = '\0',
                                        .OidMfgDateTime = '\0',   /* Set to SAHPI_TIME_UNSPECIFIED */
                                        .OidManufacturer = ".1.3.6.1.4.1.2.3.51.2.2.21.8.1.1.3.x",
                                        .OidProductName = '\0',
                                        .OidProductVersion = ".1.3.6.1.4.1.2.3.51.2.2.21.8.1.1.5.x",
                                        .OidSerialNumber = '\0',
                                        .OidPartNumber = ".1.3.6.1.4.1.2.3.51.2.2.21.8.1.1.4.x",
                                        .OidFileId = '\0',
                                        .OidAssetTag = '\0',
                                }
                        },
                },
                .comment = "Power Module VPD",
        },

        {} /* Terminate array with a null element */
};

/****************************
 * Physical Slot VPD
 ****************************/

struct snmp_bc_inventory snmp_bc_slot_inventories[] = {

        {} /* Terminate array with a null element */
};
