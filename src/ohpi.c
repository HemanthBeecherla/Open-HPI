/*      -*- linux-c -*-
 *
 * (C) Copright IBM Corp 2004
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  This
 * file and program are licensed under a BSD style license.  See
 * the Copying file included with the OpenHPI distribution for
 * full licensing terms.
 *
 * Authors:
 *     Renier Morales <renierm@users.sourceforge.net>
 */

#include <oHpi.h>
#include <oh_config.h>
#include <oh_init.h>
#include <oh_plugin.h>
#include <oh_error.h>
#include <oh_lock.h>
#include <config.h>
/* Version Call */

/**
 * oHpiVersionGet
 *
 * Returns the version of the library as an SaHpiUint64T.  The version
 * consists of 4 16 bit ints, MAJOR, MINOR, PATCH, and TYPE.  TYPE
 * is used to determine if this is the stand alone library or the client library.
 */

SaHpiUint64T oHpiVersionGet()
{
        SaHpiUint64T v = 0;
        char * version = VERSION;
        char * start = version;
        char * end = version;

        v += (strtoull(start, &end, 10) << 48);
        end++;
        start = end;
        v += (strtoull(start, &end, 10) << 32);
        end++;
        start = end;
        v += (strtoull(start, &end, 10) << 16);
        return v;
}

/* Plugin operations */

/**
 * oHpiPluginLoad
 * @name: IN. String. name of plugin to load (e.g. "libdummy")
 *
 * Loads plugin into library creating a plugin object.
 *
 * Returns: SA_OK on success. Minus SA_OK on error.
 **/
SaErrorT oHpiPluginLoad(char *name)
{
        if (!name) {
                dbg("Invalid parameters.");
                return SA_ERR_HPI_INVALID_PARAMS;
        }
        
        if (oh_init()) return SA_ERR_HPI_INTERNAL_ERROR;

        if (oh_load_plugin(name))
                return SA_ERR_HPI_ERROR;

        return SA_OK;
}

/**
 * oHpiPluginUnload
 * @name: IN. String. name of plugin to unload (e.g. "libdummy")
 *
 * Unload plugin from library, destroying the plugin object.
 * This will return an error if there are any handlers referencing
 * the plugin (e.g. refcount > 1).
 *
 * Returns: SA_OK on success. Minus SA_OK on error.
 **/
SaErrorT oHpiPluginUnload(char *name)
{
        if (!name) {
                dbg("Invalid parameters.");
                return SA_ERR_HPI_INVALID_PARAMS;
        }
        
        if (oh_init()) return SA_ERR_HPI_INTERNAL_ERROR;

        if (oh_unload_plugin(name))
                return SA_ERR_HPI_ERROR;

        return SA_OK;
}

/**
 * oHpiPluginInfo
 * @name: IN. String. name of plugin to query (e.g. "libdummy")
 * @info: IN/OUT. Reference to information structure on the plugin.
 *
 * Fetches the information associated with the plugin and puts it
 * in @info. As of yet, @info only contains the refcount for the
 * plugin.
 *
 * Returns: SA_OK on success. Minus SA_OK on error.
 **/
SaErrorT oHpiPluginInfo(char *name, oHpiPluginInfoT *info)
{
        struct oh_plugin *p = NULL;

        if (!name || !info) {
                dbg("Invalid parameters.");
                return SA_ERR_HPI_INVALID_PARAMS;
        }
        
        if (oh_init()) return SA_ERR_HPI_INTERNAL_ERROR;

        p = oh_get_plugin(name);
        if (!p) {
                dbg("Plugin %s not found.", name);
                return SA_ERR_HPI_NOT_PRESENT;
        }

        info->refcount = p->handler_count;
        oh_release_plugin(p);

        return SA_OK;
}

/**
 * oHpiPluginGetNext
 * @name: IN. String. name of plugin to search for (e.g. "libdummy")
 * @next_name: IN/OUT. Next plugin after @name will be placed here.
 * @size: IN. Size in bytes of the @next_name buffer.
 *
 * Searches for the specified plugin and returns the next plugin name
 * after that one in the list. If you pass NULL in @name, you will get
 * the name of the first plugin in @next_name. Used to iterate through
 * all loaded plugins.
 *
 * Returns: SA_OK on success. Minus SA_OK on error.
 **/
SaErrorT oHpiPluginGetNext(char *name, char *next_name, int size)
{
        if (!next_name) {
                dbg("Invalid parameters.");
                return SA_ERR_HPI_INVALID_PARAMS;
        }
        
        if (oh_init()) return SA_ERR_HPI_INTERNAL_ERROR;

        if (oh_getnext_plugin_name(name, next_name, size))
                return SA_ERR_HPI_NOT_PRESENT;

        return SA_OK;
}


/* Handler operations */

/**
 * oHpiHandlerCreate
 * @config: IN. Hash table. Holds configuration information used by handler.
 * @id: IN/OUT. The id of the newly created handler is returned here.
 *
 * Creates a new handler (instance of a plugin). Plugin handlers are what
 * respond to most API calls.
 * @config needs to have an entry for "plugin" in order to know for which
 * plugin the handler is being created.
 *
 * Returns: SA_OK on success. Minus SA_OK on error.
 **/
SaErrorT oHpiHandlerCreate(GHashTable *config,
                           oHpiHandlerIdT *id)
{
        oHpiHandlerIdT hid = 0;

        if (!config || !id) {
                dbg("Invalid parameters.");
                return SA_ERR_HPI_INVALID_PARAMS;
        }
        
        if (oh_init()) return SA_ERR_HPI_INTERNAL_ERROR;

        if (!(hid = oh_create_handler(config))) {
             *id = 0;
             return SA_ERR_HPI_ERROR;
        }

        *id = hid;

        return SA_OK;
}

/**
 * oHpiHandlerDestroy
 * @id: IN. The id of the handler to destroy
 *
 * Destroys a handler. Calls the plugin's abi close function.
 *
 * Returns: SA_OK on success. Minus SA_OK on error.
 **/
SaErrorT oHpiHandlerDestroy(oHpiHandlerIdT id)
{
        if (!id)
                return SA_ERR_HPI_INVALID_PARAMS;
                
        if (oh_init()) return SA_ERR_HPI_INTERNAL_ERROR;

        if (oh_destroy_handler(id))
                return SA_ERR_HPI_ERROR;

        return SA_OK;
}

/**
 * oHpiHandlerInfo
 * @id: IN. The id of the handler to query
 * @info: IN/OUT. Pointer to struct for holding handler information
 *
 * Queries a handler for the information associated with it.
 *
 * Returns: SA_OK on success. Minus SA_OK on error.
 **/
SaErrorT oHpiHandlerInfo(oHpiHandlerIdT id, oHpiHandlerInfoT *info)
{
        struct oh_handler *h = NULL;

        if (!id || !info)
               return SA_ERR_HPI_INVALID_PARAMS;

	if (oh_init()) return SA_ERR_HPI_INTERNAL_ERROR;

        h = oh_get_handler(id);
        if (!h) {
                dbg("Handler %d not found.", id);
                return SA_ERR_HPI_NOT_PRESENT;
        }

        strncpy(info->plugin_name, h->plugin_name, MAX_PLUGIN_NAME_LENGTH);
        oh_release_handler(h);

        return SA_OK;
}

/**
 * oHpiHandlerGetNext
 * @id: IN. Id of handler to search for.
 * @next_id: IN/OUT. The id of the handler next to the handler being searched for
 * will be returned here.
 *
 * Used for iterating through all loaded handlers. If you pass
 * 0 (SAHPI_FIRST_ENTRY), you will get the id of the first handler returned
 * in next_id.
 *
 * Returns: SA_OK on success. Minus SA_OK on error.
 **/
SaErrorT oHpiHandlerGetNext(oHpiHandlerIdT id, oHpiHandlerIdT *next_id)
{
        if (!next_id) {
                dbg("Invalid parameters.");
                return SA_ERR_HPI_INVALID_PARAMS;
        }
        
        if (oh_init()) return SA_ERR_HPI_INTERNAL_ERROR;

        if (oh_getnext_handler_id(id, next_id))
                return SA_ERR_HPI_NOT_PRESENT;

        return SA_OK;
}

/* Global parameters */

/**
 * oHpiGlobalParamGet
 * @param: param->type needs to be set to know what parameter to fetch.
 *
 * Gets the value of the specified global parameter.
 *
 * Returns: SA_OK on success. Minus SA_OK on error.
 **/
SaErrorT oHpiGlobalParamGet(oHpiGlobalParamT *param)
{
        struct oh_global_param p;

        if (!param || !param->Type) {
                dbg("Invalid parameters. oHpiGlobalParamGet()");
                return SA_ERR_HPI_INVALID_PARAMS;
        }
        
        if (oh_init()) return SA_ERR_HPI_INTERNAL_ERROR;

        p.type = param->Type;

        if (oh_get_global_param(&p))
                return SA_ERR_HPI_UNKNOWN;

        memcpy(&param->u, &p.u, sizeof(oh_global_param_union));

        return SA_OK;
}

/**
 * oHpiGlobalParamSet
 * @param: param->type needs to be set to know what parameter to set.
 * Also, the appropiate value in param->u needs to be filled in.
 *
 * Sets a global parameter.
 *
 * Returns: SA_OK on success. Minus SA_OK on error.
 **/
SaErrorT oHpiGlobalParamSet(oHpiGlobalParamT *param)
{
        struct oh_global_param p;

        if (!param || !param->Type) {
                dbg("Invalid parameters. oHpiGlobalParamSet()");
                return SA_ERR_HPI_INVALID_PARAMS;
        }
        
        if (oh_init()) return SA_ERR_HPI_INTERNAL_ERROR;

        p.type = param->Type;
        memcpy(&p.u, &param->u, sizeof(oh_global_param_union));

        if (oh_set_global_param(&p))
                return SA_ERR_HPI_ERROR;

        return SA_OK;
}

/**
 * oHpiInjectEvent
 * @id: id of handler into which the event will be injected.
 * @event: pointer to the event to be injected.
 * @rpte: pointer to the resource to be injected.
 * @rdrs: pointer to the list of RDRs to be injected along with @resoruce
 *
 * @id and @event are required parameters. @rpte is only required if the event
 * is of RESOURCE type or HOTSWAP type. @rdrs is an optional argument in all
 * cases and can be NULL. If @rdrs is passed, it will be copied. It is the
 * responsibility of the caller to clean up the RDRs list once it is used here.
 *
 * Returns: SA_OK on success. This call will set the event.Source, rpte.ResourceId,
 * rpte.ResourceEntity so that the caller knows what the final assigned values were.
 * For rpte.ResourceEntity, the entity_root configuration parameter for the plugin
 * is used to complete it. In addition, for each rdr in @rdrs, a Num, RecordId,
 * and Entity will be assigned. This will also be reflected in the passed @rdrs
 * list so that the caller can know what the assigned values were.
 **/
SaErrorT oHpiInjectEvent(oHpiHandlerIdT id,
			 SaHpiEventT *event,
			 SaHpiRptEntryT *rpte,
			 GSList *rdrs)
{
	SaErrorT (*inject_event)(void *hnd,
                            	 SaHpiEventT *evt,
                            	 SaHpiRptEntryT *rpte,
                            	 GSList *rdrs);

	struct oh_handler *h = NULL;
	SaErrorT error = SA_OK;

	if (!id) {
		dbg("Invalid handler id %d passed",id);
		return SA_ERR_HPI_INVALID_PARAMS;
	} else if (!event) {
		dbg("Invalid NULL event passed");
		return SA_ERR_HPI_INVALID_PARAMS;
	}

	if (oh_init()) return SA_ERR_HPI_INTERNAL_ERROR;

	h = oh_get_handler(id);
	inject_event = h ? h->abi->inject_event : NULL;
        if (!inject_event) {
                oh_release_handler(h);
                return SA_ERR_HPI_INVALID_CMD;
        }

	error = inject_event(h->hnd, event, rpte, rdrs);
        if (error) {
                dbg("Event injection into handler %d failed", id);
        }

        oh_release_handler(h);
        return error;
}

