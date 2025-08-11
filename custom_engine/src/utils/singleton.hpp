#pragma once

#include <type_traits>

namespace Utils
{

    /**
     * @brief Implementation of the "base singleton class"
     *
     * Implemented using Mayers' Singleton pattern
     *
     * Neither CopyConstructible/MoveConstructible nor
     * CopyAssignable/MoveAssignable
     */
    template <typename T>
    class CSingleton
    {
    public:
        /**
         * @brief Returns the only one existing instance of type T
         *
         * @return Instance
         * @throw Runtime error when provided type is not base of CSingleton
         */
        static T &GetInstance()
        {
            const bool expr = std::is_base_of<CSingleton, T>::value;

            if (!expr)
            {
                throw std::runtime_error("Provided type is not base of CSingleton");
            }

            static T instance;
            return instance;
        }

        CSingleton(const CSingleton &ct_Source) = delete;
        CSingleton(CSingleton &&t_Source) = delete;

        CSingleton &operator=(const CSingleton &ct_RHV) = delete;
        CSingleton &operator=(CSingleton &&t_RHV) = delete;

        virtual ~CSingleton() = default;

    protected:
        CSingleton() = default;
    };

} // namespace Utils
