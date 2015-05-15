//
// Created by Chris on 4/26/2015.
//

#ifndef SDLTESTCLION_RESPATH_H
#define SDLTESTCLION_RESPATH_H

#include <string>
#include "../utility/common.h"




class ResPath{

    const static int DEBUG = 1;
    /*
    * Get the resource path for resources located in res/subDir
    * It's assumed the project directory is structured like:
    * bin/
    *  the executable
    * res/
    *  Lesson1/
    *  Lesson2/
    *
    * Paths returned will be Lessons/res/subDir
    */
public:
    static std::string getResPath(const std::string &subDir = ""){
        //We need to choose the path separator properly based on which
        //platform we're running on, since Windows uses a different
        //separator than most systems
#ifdef _WIN32
		const char PATH_SEP = '\\';
		const std::string debugRespath = "C:\\";
#else
        const char PATH_SEP = '/';
        const std::string debugRespath = "/home/christopher/ClionProjects/SDLTestCLion/res";
#endif
        //This will hold the base resource path: Lessons/res/
        //We give it static lifetime so that we'll only need to call
        //SDL_GetBasePath once to get the executable path
        static std::string baseRes;
        if (baseRes.empty()){
            //SDL_GetBasePath will return NULL if something went wrong in retrieving the path
            char *basePath = SDL_GetBasePath();
            if (basePath){
                baseRes = basePath;
                SDL_free(basePath);
            }
            else {
                std::cerr << "Error getting resource path: " << SDL_GetError() << std::endl;
                return "";
            }
            //We replace the last bin/ with res/ to get the the resource path
            size_t pos = baseRes.rfind("bin");
            baseRes = baseRes.substr(0, pos) + "res" + PATH_SEP;
        }
        if(DEBUG) return debugRespath + subDir + PATH_SEP;
        return subDir.empty() ? baseRes : baseRes + subDir + PATH_SEP;
    }
};


#endif //SDLTESTCLION_RESPATH_H
