#ifndef DDEBUG
#define DDEBUG 0
#endif
#include "ddebug.h"


#include "ngx_http_lua_graphite.h"
#include "ngx_http_lua_util.h"


typedef ngx_int_t (*ngx_http_graphite_custom_pt)(ngx_http_request_t*, ngx_str_t*, double);


static ngx_http_graphite_custom_pt custom_pt = NULL;
static int ngx_http_lua_graphite_custom(lua_State *L);


void
ngx_http_lua_inject_graphite_api(lua_State *L)
{
    ngx_str_t name = ngx_string("graphite_custom");

    int i;
    for (i = 0; ngx_modules[i]; i++) {

        ngx_module_t *module = ngx_modules[i];
        if (module->type != NGX_HTTP_MODULE)
            continue;

        ngx_command_t *cmd = module->commands;
        if (cmd == NULL)
            continue;

        for (; cmd->name.len; cmd++) {
            if ((cmd->name.len == name.len) && (ngx_strncmp(cmd->name.data, name.data, name.len) == 0)) {
                custom_pt = cmd->post;
            }
        }
    }

    lua_pushcfunction(L, ngx_http_lua_graphite_custom);
    lua_setfield(L, -2, "graphite");
}


static int
ngx_http_lua_graphite_custom(lua_State *L) {

    ngx_http_request_t *r;
    r = ngx_http_lua_get_req(L);

    if (r == NULL) {
        return luaL_error(L, "no request object found");
    }

    double value = lua_tonumber(L, -1);
    lua_pop(L, 1);

    ngx_str_t name;
    name.data = (u_char*)lua_tolstring(L, -1, &name.len);
    if (name.data == NULL)
        return 0;
    lua_pop(L, 1);

    if (custom_pt)
        custom_pt(r, &name, value);

    return 0;
}
