#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    enum state { L610 = 0 , READ = 1, TEMP = 2, HUMIDITY = 3, CARBON = 4, LUXLIGHT = 5 ,UPLOADSENSOR = 6, TOFINIT = 7, TOFDIS = 8 , TOFDESTROY = 9, SHOOTPIC=10, CAMERAINIT = 11, CAMERADIS = 12, CAMERADESTROY = 13, FATIGUEINIT = 14, FATIGUEDIS = 15, FATIGUEDESTROY = 16, RUNPRECLOS = 17, DEBUGDIS = 18};
public:
    state tag = L610;
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void SensorRead();
    void LightRead();
    void debugdis();
    float getTempvalue();
    float getHumivalue();
    float getCO2value();
    int getLightvalue();
    int getTofvalue();
    float getFatiguevalue();
    void upload();
    void L610Init();
    void tofdis();
    void tofinit();
    void tofdestroy();
    void cameradis();
    void camerainit();
    void cameradestroy();
    void fatiguedis();
    void fatigueinit();
    void fatiguedestroy();
    void runpreclos();
    void shootapicture();
    int tickCounter;
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
