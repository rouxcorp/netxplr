#ifndef NX_MACPORT_H
#define NX_MACPORT_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>

#include "../common/primitives/macaddr.h"
#include "../common/primitives/ipaddr.h"

using namespace std;

// http://www.cisco.com/c/en/us/support/docs/ip/simple-network-management-protocol-snmp/40367-camsnmp40367.html
const oid oid_port_table[]	= {1, 3, 6, 1, 2, 1, 17, 4, 3, 1, 2};
const oid oid_ifindex_table[]	= {1, 3, 6, 1, 2, 1, 17, 1, 4, 1, 2};
const oid oid_ifname_table[]	= {1, 3, 6, 1, 2, 1, 31, 1, 1, 1, 1};

const size_t len_port_table	= sizeof(oid_port_table)	/ sizeof(oid);
const size_t len_ifindex_table	= sizeof(oid_ifindex_table)	/ sizeof(oid);
const size_t len_ifname_table	= sizeof(oid_ifname_table)	/ sizeof(oid);

void append_oid_mac(macaddr_t mac, oid* oid_out, size_t* oid_len);

map<string, string> confMap;
void read_conf(const char* file);

bool initialized = false;

extern "C" {
	void __attribute__ ((constructor)) load(void);
	void __attribute__ ((destructor)) unload(void);

	void initialize(const char* conf_file);
	long int lookup_mac(macaddr_t mac);
}

#endif
