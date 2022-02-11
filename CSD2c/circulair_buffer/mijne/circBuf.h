
class circBuf{
    public:
        circBuf(int size, int numSamplesDelay);
        ~circBuf();

        void addValue(float newValue);
        float readValue();
        float wrap(int point);

    protected: 
        int size;
        int numSamplesDelay;

        float* buffer;
        
        int writePoint;
        int readPoint;

};

