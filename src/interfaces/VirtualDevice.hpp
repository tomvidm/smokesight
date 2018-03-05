#ifndef VIRTUALDEVICE_HPP
#define VIRTUALDEVICE_HPP

namespace interfaces {
    class VirtualDevice {
    private:
        uint64_t m_id;
        bool m_active;
    }; // class VirtualDevice
} // namespace if

#endif