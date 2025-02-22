#ifndef PERCOM_HPP
#define PERCOM_HPP

template <class T>
class Operator {
protected:
    T value;
public:
    constexpr Operator(T value) : value(value) {}
    virtual constexpr T operator->*(T r) const = 0;
};

template <class T>
class P_Op : public Operator<T> {
public:
    using Operator<T>::Operator;
    constexpr T operator->*(T r) const override {
        T result = 1;
        for (T i = 0; i < r; ++i) {
            result *= this->value - i;
        }
        return result;
    }
};

template <class T>
class C_Op : public Operator<T> {
public:
    using Operator<T>::Operator;
    constexpr T operator->*(T r) const override {
        return P_Op<T>(this->value)->*r / P_Op<T>(r)->*r;
    }
};

template <template <class> class Op>
class Helper {};

template <template <class> class Op>
constexpr auto operator->*(auto n, Helper<Op>) {
    return Op<decltype(n)>(n);
}

#define P ->* Helper<P_Op>() ->*
#define C ->* Helper<C_Op>() ->*

#endif