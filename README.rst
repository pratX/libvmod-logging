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

Vmod for logging backend response body, for Varnish 3.0.
Its a wrapper over _object_read function in https://github.com/aivarsk/libvmod-rewrite

FUNCTIONS
=========

log_obj_body
------------

Prototype
        ::

                log_obj_body(STRING PREFIX)
Return value
        VOID
Description
        Logs backend response body to syslog LOG_LOCAL4|LOG_INFO

        WARNING:To be called only from vcl_deliver, else worker process will crash.

INSTALLATION
============

Usage::

 ./autogen.sh 
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


