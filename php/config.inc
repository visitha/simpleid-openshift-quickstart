<?php
/**
 * SimpleID OpenShift configuration file
 *
 * This file sets up various configuration items for deploying SimpleID on
 * the OpenShift platform.  It then reads config/config.php from the
 * OpenShift data directory to complete the configruation process.
 *
 * @package openshift
 */
 
// Define OpenShift environment variables
define('OPENSHIFT_APP_DNS', getenv('OPENSHIFT_APP_DNS'));
define('OPENSHIFT_DATA_DIR', getenv('OPENSHIFT_DATA_DIR'));
define('OPENSHIFT_REPO_DIR', getenv('OPENSHIFT_REPO_DIR'));

// Define SimpleID configuration for OpenShift distribution
define('SIMPLEID_CLEAN_URL', true);
define('SIMPLEID_IDENTITIES_DIR', OPENSHIFT_DATA_DIR . 'identities');
define('SIMPLEID_CACHE_DIR', OPENSHIFT_DATA_DIR . 'cache');
define('SIMPLEID_STORE_DIR', OPENSHIFT_DATA_DIR . 'store');

// Now load the configuration file in the OpenShift data directory
// Note this is always config.php regardless of the SimpleID version
$openshift_config_file = OPENSHIFT_DATA_DIR . 'config/config.php';
if (file_exists($openshift_config_file)) {
    include_once $openshift_config_file;
}

// Now load additional defaults if they are not defined in the OpenShift data
// directory configuration file

// Note that define_default() is not yet defined, so we have to do it manually
if (!defined('SIMPLEID_BASE_URL'))
    define('SIMPLEID_BASE_URL', 'http://' . OPENSHIFT_APP_DNS);
if (!defined('SIMPLEID_STORE')) define('SIMPLEID_STORE', 'filesystem');
?>
