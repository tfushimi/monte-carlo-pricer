#ifndef Parameter_hpp
#define Parameter_hpp

class ParameterInner {
public:
    ParameterInner(){}
    virtual ParameterInner* clone() const = 0;
    virtual double integral(double timeStart, double timeEnd) const = 0;
    virtual double integralSquare(double timeStart, double timeEnd) const = 0;
    virtual ~ParameterInner(){}
};


class ParameterConstant: public ParameterInner {
public:
    ParameterConstant(double constant);
    
    virtual ParameterInner* clone() const;
    virtual double integral(double timeStart, double timeEnd) const;
    virtual double integralSquare(double timeStart, double timeEnd) const;
    
private:
    double constant;
    double constantSquare;
};

class Parameter {
public:
    Parameter(const ParameterInner& parameterInner);
    Parameter(const Parameter& original);
    Parameter& operator=(const Parameter& original);
    virtual ~Parameter();
    
    inline double integral(double timeStart, double timeEnd) const;
    inline double integralSquare(double timeStart, double timeEnd) const;
    
    double mean(double timeStart, double timeEnd) const;
    double rootMeanSquare(double timeStart, double timeEnd) const;

private:
    ParameterInner* parameterInner;
};

inline double Parameter::integral(double timeStart, double timeEnd) const {
    return parameterInner->integral(timeStart, timeEnd);
}

inline double Parameter::integralSquare(double timeStart, double timeEnd) const {
    return parameterInner->integralSquare(timeStart, timeEnd);
}

#endif /* Parameter_hpp */
