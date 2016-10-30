#!/usr/bin/python
# -*- encoding:utf-8 -*-

import sys
from netaddr import *

def main(args):

    ip = IPNetwork(args[0])
    val = ip.ip.bits()

    ip1 = IPNetwork(args[1])
    val1 = ip1.ip.bits()

    val = val.replace(".", "")
    val1 = val1.replace(".", "")

    val = val[:int(args[2])]
    val1 = val1[:int(args[2])]

    print "first", ip.ip, ip.network, ip.broadcast
    print "second", ip1.ip, ip1.network, ip1.broadcast
    print val
    print val1
    print ip1.ip > ip.network and ip1.ip < ip.broadcast
    print ip.ip > ip1.network and ip.ip < ip1.broadcast
    print val == val1

if __name__ == "__main__":
        main(sys.argv[1:])
