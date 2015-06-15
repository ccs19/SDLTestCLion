// DO NOT OVERWRITE THIS
// Use this template to set path of certain files
// Name copy to be used resource_path.h
//

#ifndef SDLTESTCLION_RESOURCE_PATH_TEMPLATE_H
#define SDLTESTCLION_RESOURCE_PATH_TEMPLATE_H

//Debug
#define DEBUG 1

//Directories
#define LOGGER_PROPERTIES "I NEED TO BE SET"/**log.properties path**/
#define DEBUG_RESPATH "SET ME PLZ" /**Resource path to use in debugging**/


//Directory constants
#define BITMAP_DIR "SET_ME" /**Name of bitmap directory. No slashes**/


/**Setting path separator by OS**/

#ifdef _WIN32
    #define PATH_SEP '\\'
#else
    #define PATH_SEP '/'
#endif //END ifdef _WIN32


#endif //SDLTESTCLION_RESOURCE_PATH_TEMPLATE_H
