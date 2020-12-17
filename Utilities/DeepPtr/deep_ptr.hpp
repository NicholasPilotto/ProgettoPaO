#ifndef DEEP_PTR_H_
#define DEEP_PTR_H_
template <class T>
class deep_ptr{
private:
    T* ptr;
public:
    deep_ptr(ptr = nullptr);
    ~deep_ptr();
    deep_ptr(const deep_ptr&);
    deep_ptr& operator=(const deep_ptr&);
    bool operator==(const deep_ptr&) const;
    bool operator!=(const deep_ptr&) const;
    bool operator<(const deep_ptr&) const;
    bool operator<=(const deep_ptr&) const;
    bool operator>(const deep_ptr&) const;
    bool operator>=(const deep_ptr&) const;
    explicit operator bool() const;
    T& operator*() const;
    T* operator->() const;
    T* operator[]() const;
};
#endif
