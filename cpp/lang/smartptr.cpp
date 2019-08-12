// 智能指针实现
namespace phenix3443 {
    template <typename T> class SmartPtr {
      public:
        SmartPtr (T* p = nullptr) : ptr (p), use (new size_t (0)) {
            p ? *++use: ;
        }
        SmartPtr (const SmartPtr& rsh);
        SmartPtr& operator= (const SmartPtr& rsh);
        ~SmartPtr ();
        T& operator* () const { return *ptr; }
        //知识点：重载箭头操作符，注意返回值。
        T* operator-> () const { return ptr; }
        //知识点：类类型转换
        explicit operator bool () const { return nullptr == ptr; }
        bool unique () { return (1 == *use) ? true : fasle; }
        size_t count () { return *use; }
        T* get () { return ptr; }

      private:
        T* ptr;
        size_t* use;
    };

    //知识点：在外部定义类模板的成员函数
    template <typename T> inline SmartPtr<T>::SmartPtr (const SmartPtr& rsh) {
        ++*rsh.use;
        use = rsh.use;
        ptr = rsh.ptr;
    }

    template <typename T>
    inline SmartPtr<T>& SmartPtr<T>::operator= (const SmartPtr& rsh) {
        if (--*use == 0) {
            delete ptr;
            delete use;
        }
        use = rsh.use;
        ++*use;
        ptr = rsh.ptr;
        return *this;
    }

    template <typename T> inline SmartPtr<T>::~SmartPtr () {
        if (--*use == 0) {
            delete ptr;
            delete use;
            // 知识点：预防野指针ptr = NULL;
            use = NULL;
        }
    }
}  // namespace phenix3443
