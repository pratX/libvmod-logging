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

Varnish vmod written out of a need to log response body.
Logs to syslog.

FUNCTIONS
=========

log_obj_body()
--------------

Prototype
        ::

                log_obj_body()
Return value
	VOID
Description
	Logs backend response body to syslog LOG_LEVEL0|LOG_INFO
        Warning: To be called only from vcl_deliver, else worker process will crash.

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

This manual page was released as part of the libvmod-example package,
written out of a need to log response body.

For further examples and inspiration check out the vmod directory:

    https://www.varnish-cache.org/vmods


