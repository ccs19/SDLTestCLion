//
// Created by chris_000 on 6/19/2015.
//

#ifndef SDLTESTCLION_RENDEROBJECT_H
#define SDLTESTCLION_RENDEROBJECT_H


class RenderObject {
private:
     unsigned long long int position; //Object's position in list for quick lookup

public:

     virtual void render() =0;
     virtual int getArrayPosition(){return position;}
     virtual void setArrayPosition(const unsigned long long int position){this->position = position;}
};


#endif //SDLTESTCLION_RENDEROBJECT_H
