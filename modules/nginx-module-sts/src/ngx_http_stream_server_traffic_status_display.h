
/*
 * Copyright (C) YoungJoo Kim (vozlt)
 */


#ifndef _NGX_HTTP_STREAM_STS_DISPLAY_H_INCLUDED_
#define _NGX_HTTP_STREAM_STS_DISPLAY_H_INCLUDED_


u_char *ngx_http_stream_server_traffic_status_display_get_time_queue(
    ngx_http_request_t *r,
    ngx_http_stream_server_traffic_status_node_time_queue_t *q,
    ngx_uint_t offset);
u_char *ngx_http_stream_server_traffic_status_display_get_time_queue_times(
    ngx_http_request_t *r,
    ngx_http_stream_server_traffic_status_node_time_queue_t *q);
u_char *ngx_http_stream_server_traffic_status_display_get_time_queue_msecs(
    ngx_http_request_t *r,
    ngx_http_stream_server_traffic_status_node_time_queue_t *q);

u_char *ngx_http_stream_server_traffic_status_display_set_main(
    ngx_http_request_t *r, u_char *buf);
u_char *ngx_http_stream_server_traffic_status_display_set_server_node(
    ngx_http_request_t *r,
    u_char *buf, ngx_str_t *key,
    ngx_http_stream_server_traffic_status_node_t *stsn);
u_char *ngx_http_stream_server_traffic_status_display_set_server(
    ngx_http_request_t *r, u_char *buf,
    ngx_rbtree_node_t *node);

u_char *ngx_http_stream_server_traffic_status_display_set_filter_node(
    ngx_http_request_t *r, u_char *buf,
    ngx_http_stream_server_traffic_status_node_t *stsn);
u_char *ngx_http_stream_server_traffic_status_display_set_filter(
    ngx_http_request_t *r, u_char *buf,
    ngx_rbtree_node_t *node);

u_char *ngx_http_stream_server_traffic_status_display_set_upstream_node(
    ngx_http_request_t *r, u_char *buf,
    ngx_stream_upstream_server_t *us,
#if nginx_version > 1007001
    ngx_http_stream_server_traffic_status_node_t *stsn
#else
    ngx_http_stream_server_traffic_status_node_t *stsn, ngx_str_t *name
#endif
    );
u_char *ngx_http_stream_server_traffic_status_display_set_upstream_alone(
    ngx_http_request_t *r, u_char *buf, ngx_rbtree_node_t *node);
u_char *ngx_http_stream_server_traffic_status_display_set_upstream_group(
    ngx_http_request_t *r, u_char *buf);

u_char *ngx_http_stream_server_traffic_status_display_set(ngx_http_request_t *r,
    u_char *buf);

char *ngx_http_stream_server_traffic_status_display(ngx_conf_t *cf,
    ngx_command_t *cmd, void *conf);


#endif /* _NGX_HTTP_STREAM_STS_DISPLAY_H_INCLUDED_ */

/* vi:set ft=c ts=4 sw=4 et fdm=marker: */
