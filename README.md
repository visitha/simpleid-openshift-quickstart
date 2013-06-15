SimpleID on OpenShift
=====================

This git repository helps you get up and running quickly with a SimpleID installation
on OpenShift.


Running on OpenShift
--------------------

1. Create an account at http://openshift.redhat.com/ and install the client tools (run 'rhc setup' first)

2. Create a php-5.3 application (you can call your application whatever you want)

    rhc app create simpleid php-5.3 --from-code=https://github.com/simpleid/simpleid-openshift-quickstart
    
3. Set up additional configuration options.  The SimpleID configuration file is
   located under the OpenShift data directory (`$OPENSHIFT_DATA_DIR/config`).
   Make a copy of the file `config.php.dist` and rename it `config.php`.
   Open the file with a text editor and edit the configuration options.
   
   (A copy of `config.php.dist` can be found in the repository at
   `.openshift/defaults/config/config.php.dist`.)
    
4. Follow the SimpleID documentation to [set up your identity](http://simpleid.koinic.net/documentation/getting-started/setting-identity).
   The identities directory is located under the OpenShift data directory
   (`$OPENSHIFT_DATA_DIR/identities`).

5. That's it, you can now checkout your application at:

    http://simpleid-$yournamespace.rhcloud.com

Notes
=====

Directories
-----------

This is how the following SimpleID directories are located on this OpenShift
distribution:

- **Cache directory** (`cache`): `$OPENSHIFT_DATA_DIR/cache`
- **Identities directory** (`identities`): `$OPENSHIFT_DATA_DIR/identities`
- **Store directory** (`store`): `$OPENSHIFT_DATA_DIR/store`
- **Web directory** (`www`): `$OPENSHIFT_REPO_DIR/php`

Repository layout
-----------------

- `php/`: Externally exposed php code goes here
- `libs/`: Additional libraries
- `misc/`: For not-externally exposed php code
- `deplist.txt`: list of pears to install
- `.openshift/defaults/`: List of configuration items that are copied over on creation
- `.openshift/action_hooks/deploy`: Script that gets run every git push after build but before the app is restarted


Action hooks
------------

GIT_ROOT/.openshift/action_hooks/deploy:
    This script is executed with every 'git push'.  Feel free to modify this script
    to learn how to use it to your advantage.  By default, this script will create
    the database tables that this example uses.


Security considerations
-----------------------
Consult the SimpleID documentation for best practices regarding securing your installation.


Licensing
---------

Licensing information for the OpenShift distribution can be found in the file COPYING.txt.

Licensing information for the core SimpleID software can be found in the
[source distribution](http://simpleid.koinic.net/download).

