#ifndef PERCOM_HPP
#define PERCOM_HPP

template <class T>
class Operator {
protected:
    T value;
public:
    Operator(T value) :value(value) {}
    virtual T operator->*(T r) = 0;
};
template <class T>
class P_Op :public Operator<T> {
public:
    using Operator<T>::Operator;
    T operator->*(T r)override {
        T result = 1;
        for (T i = 0; i < r; ++i) {
            result *= this->value - i;
        }
        return result;
    }
};
template <class T>
class C_Op :public Operator<T> {
public:
    using Operator<T>::Operator;
    T operator->*(T r)override {
        return P_Op(this->value)->*r / P_Op(r)->*r;
    }
};
template <template <class> class Op>
class Helper {};
template <template <class> class Op>
auto operator->*(auto n, Helper<Op>) {
    return Op<decltype(n)>(n);
}

#define P ->* Helper<P_Op>() ->*
#define C ->* Helper<C_Op>() ->*


#endif