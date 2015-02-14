============
vmod_logging
============

----------------------
Varnish Logging Module
----------------------

:Author: Pratik Kumar
:Date: 2015-02-14
:Version: 1.0
:Manual section: 3

SYNOPSIS
========

import logging;

DESCRIPTION
===========

Vmod for logging client request, backend response, both header and body, for Varnish 3.0.

FUNCTIONS
=========

log_client_req
--------------

Prototype
        ::

                log_client_req()
Return value
        VOID
Description
        Logs client request first line and headers to syslog LOG_LOCAL0|LOG_INFO
        
Example
        ::

                logging.log_client_req();


log_beresp
----------

Prototype
        ::

                log_beresp()
Return value
	VOID
Description
	Logs backend response first line and  headers to syslog LOG_LOCAL0|LOG_INFO
        WARNING:To be called only from vcl_fetch, else worker process will crash. 
Example
        ::

                logging.log_beresp();

log_obj_body
------------

Prototype
        ::

                log_obj_body()
Return value
        VOID
Description
        Logs backend response body to syslog LOG_LOCAL0|LOG_INFO
        WARNING:To be called only from vcl_deliver, else worker process will crash.
Example
        ::

                logging.log_obj_body();


INSTALLATION
============

Usage::

 ./configure VARNISHSRC=DIR [VMODDIR=DIR]

`VARNISHSRC` is the directory of the Varnish source tree for which to
compile your vmod. Both the `VARNISHSRC` and `VARNISHSRC/include`
will be added to the include search paths for your module.

Optionally you can also set the vmod install directory by adding
`VMODDIR=DIR` (defaults to the pkg-config discovered directory from your
Varnish installation).

Make targets:

* make - builds the vmod
* make install - installs your vmod in `VMODDIR`

HISTORY
=======

This manual page was released as part of the libvmod-logging package,
written out of need for logging http response body.

For further examples and inspiration check out the vmod directory:

    https://www.varnish-cache.org/vmods


