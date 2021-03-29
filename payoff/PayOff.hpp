#ifndef PayOff_hpp
#define PayOff_hpp

class PayOff {
public:
    PayOff(){};
    virtual double operator()(double spot) const=0;
    virtual ~PayOff(){};
    virtual PayOff* clone() const=0;
};

class PayOffCall: public PayOff {
public:
    PayOffCall(double strike);
    virtual double operator()(double spot) const;
    virtual ~PayOffCall(){};
    virtual PayOff* clone() const;
    
private:
    double strike;
};

class PayOffPut: public PayOff {
public:
    PayOffPut(double strike);
    virtual double operator()(double spot) const;
    virtual ~PayOffPut(){};
    virtual PayOff* clone() const;
    
private:
    double strike;
    
};
#endif
