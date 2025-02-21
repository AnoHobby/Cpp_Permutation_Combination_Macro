#ifndef PERCOM_HPP
#define PRECOM_HPP
template <class T>
class __CalculatorBase {
protected:
    T r;
public:
    constexpr __CalculatorBase(T r) : r(r) {}
    virtual constexpr T calculate(T n) const = 0;
};

template <class T>
class __P_Calculator : public __CalculatorBase<T> {
public:
    using __CalculatorBase<T>::__CalculatorBase;
    constexpr T calculate(T n) const override {
        T result = 1;
        for (T i = 0; i < this->r; ++i) {
            result *= n - i;
        }
        return result;
    }
};

template <class T>
class __C_Calculator : public __CalculatorBase<T> {
public:
    using __CalculatorBase<T>::__CalculatorBase;
    constexpr T calculate(T n) const override {
        return (__P_Calculator<T>(this->r).calculate(n)) / (__P_Calculator<T>(this->r).calculate(this->r));
    }
};

template <class T>
constexpr T operator+(T n, const __CalculatorBase<T>& calc) {
    return calc.calculate(n);
}

template <template <class> class Calculator>
class __Helper {
public:
    constexpr auto operator*(auto r) {
        return Calculator<decltype(r)>(r);
    }
};
#define P + __Helper<__P_Calculator>() *
#define C + __Helper<__C_Calculator>() *
#endif