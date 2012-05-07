/*
 * @author Mário Soares
 * @contributors Jefferson González
 * 
 * @license 
 * This file is part of wxPHP check the LICENSE file for information.
 * 
 * @description
 * Main start point for the wxWidgets php extension
 * 
 * @note
 * Some parts of this file are auto-generated by the wxPHP source maker
*/

#include "php_wxwidgets.h"
#include "app.h"
#include "functions.h"

/**
 * To enable inclusion of class methods tables entries code 
 * on the generated headers
 */
#define WXPHP_INCLUDE_METHOD_TABLES

/**
 * Space reserved for the zend_class_entry declaration of each class
 * as the resource id and its include files
 */
<?php print $entries ?>

/**
 * Predefined handcoded class entry for wxApp
 */
zend_class_entry *php_wxApp_entry;
int le_wxApp;

/**
 * Custom function to register global objects as constants
 */
BEGIN_EXTERN_C()
void wxphp_register_resource_constant(const char *name, uint name_len, void* resource, zend_class_entry* class_entry, int list_entry, int flags, int module_number TSRMLS_DC)
{
	zend_constant c;
	char _wxResource[] = "wxResource";
	
	object_init_ex(&c.value, class_entry);
	add_property_resource(&c.value, _wxResource, zend_list_insert(resource, list_entry));
	
	c.value.type = IS_OBJECT;
	c.flags = flags;
	c.name = zend_strndup(name, name_len-1);
	c.name_len = name_len;
	c.module_number = module_number;
	zend_register_constant(&c TSRMLS_CC);
}
END_EXTERN_C()

/**
 * Global functions table entry used on the module initialization code
 */
static zend_function_entry php_wxWidgets_functions[] = {
	PHP_FALIAS(wxInitAllImageHandlers, php_wxInitAllImageHandlers, NULL)
	PHP_FALIAS(wxExecute, php_wxExecute, NULL)
	PHP_FALIAS(wxInitialize, php_wxInitialize, NULL)
	PHP_FALIAS(wxEntry, php_wxEntry, NULL)
	PHP_FALIAS(wxAboutBox, php_wxAboutBox, NULL)
	PHP_FALIAS(wxC2D, php_wxC2D, NULL)
	
	/**
	 * Space reserved for the addition to functions table of
	 * autogenerated functions
	 */
<?php print $functions_table ?>

	PHP_FE_END //Equivalent to { NULL, NULL, NULL, 0, 0 } at time of writing on PHP 5.4
};

PHP_RINIT_FUNCTION(php_wxWidgets)
{
	static int objects_intialized = 0;
	
	/**
	 * Space reserved for the initialization of global object 
	 * constants, since the php engine doesnt initializes the object
	 * store prior to calling extensions MINIT function.
	 * 
	 * Note:
	 * 
	 * Predefined fonts, pens brushes, colors and cursos are  initilized 
	 * by 'wxStockGDI::instance().Get*(item)' functions and it needs 
	 * wxInitilize call in order to work (learned this the hard way)
	 */
	 
	if(objects_intialized < 1)
	{
		wxInitialize();
	 
<?php print $object_constants ?>
	
		wxUninitialize();
		
		objects_intialized = 1;
	}
		
    return SUCCESS;
}

PHP_MINIT_FUNCTION(php_wxWidgets)
{
    zend_class_entry ce; /* Temporary variable used to initialize class entries */

	/**
	 * Predefined Initialization of wxApp class
	 */
	char PHP_wxApp_name[] = "wxApp";
	INIT_CLASS_ENTRY(ce, PHP_wxApp_name, php_wxApp_functions);
	php_wxApp_entry = zend_register_internal_class(&ce TSRMLS_CC);
	le_wxApp = zend_register_list_destructors_ex(NULL,NULL, (char*) "native wxApp", module_number);
	
	/**
	 * Space reserved for the initialization of autogenerated classes,
	 * class enumerations and global constants
	 */
	  
<?php print $classes ?>
	
    return SUCCESS;
}

/**
 * TODO: Automate the process of updating versions number
 * Show version information to phpinfo()
 */
PHP_MINFO_FUNCTION(php_wxWidgets)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "wxWidgets", "enabled");
	php_info_print_table_row(2, "Extension Version", PHP_WXWIDGETS_EXTVER);
	php_info_print_table_row(2, "wxWidgets Version", PHP_WXWIDGETS_VERSION);
	php_info_print_table_end();
}


/**
 * Declaration of wxWidgets module
 */
zend_module_entry wxWidgets_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_WXWIDGETS_EXTNAME,
    php_wxWidgets_functions, 	/* Functions (module functions) */
    PHP_MINIT(php_wxWidgets), 	/* MINIT (module initialization function) */
    NULL, 						/* MSHUTDOWN (module shutdown function) */
    PHP_RINIT(php_wxWidgets),	/* RINIT (request initialization function) */
    NULL, 						/* RSHUTDOWN (request shutdown function) */
    PHP_MINFO(php_wxWidgets),	/* MINFO (module information function) */
    PHP_WXWIDGETS_EXTVER,
    STANDARD_MODULE_PROPERTIES
};

/**
 * Insertion of wxWidgets module to the PHP runtime
 */
#ifdef COMPILE_DL_WXWIDGETS
extern "C" {
ZEND_GET_MODULE(wxWidgets)
}
#endif
