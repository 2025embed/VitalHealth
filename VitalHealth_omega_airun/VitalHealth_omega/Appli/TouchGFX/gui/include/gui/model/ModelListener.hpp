#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }
    virtual void newjunctiontemp(float value) {}
    virtual void newjunctionHumi(float value) {}
    virtual void newjunctionCO2(float value) {}
    virtual void newjunctionLight(int value) {}
    virtual void newjunctionTOF(int value) {}
    virtual void newjunctionFatigue(float value) {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
