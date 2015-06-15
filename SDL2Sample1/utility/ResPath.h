//
// Created by Chris on 4/26/2015.
//

#ifndef SDLTESTCLION_RESPATH_H
#define SDLTESTCLION_RESPATH_H

#include <string>
#include "../utility/common.h"
#include "resource_path.h"



class ResPath{
private:

public:

    /**
    * Returns resource path
    */
    static std::string getResPath(const std::string &subDir = ""){
        static std::string baseRes;
        if (baseRes.empty()){
            char *basePath = SDL_GetBasePath();
            if (basePath){
                baseRes = basePath;
                SDL_free(basePath);
            }
            else {
                std::cerr << "Error getting resource path: " << SDL_GetError() << std::endl;
                return "";
            }

            size_t pos = baseRes.rfind("bin");
            baseRes = baseRes.substr(0, pos) + "res" + PATH_SEP;
        }
        if(DEBUG) return DEBUG_RESPATH + subDir + PATH_SEP;
        return subDir.empty() ? baseRes : baseRes + subDir + PATH_SEP;
    }

    static std::string getBitmapPath(){
        return getResPath() +  BITMAP_DIR + PATH_SEP;
    }
};


#endif //SDLTESTCLION_RESPATH_H
