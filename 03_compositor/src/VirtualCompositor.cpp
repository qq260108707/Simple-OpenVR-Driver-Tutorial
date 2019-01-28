#include "VirtualCompositor.hpp"

VirtualCompositor::VirtualCompositor() {
	_serial = "vc_" + std::to_string(std::chrono::system_clock::now().time_since_epoch().count());
}

std::shared_ptr<VirtualCompositor> VirtualCompositor::make_new()
{
	return std::shared_ptr<VirtualCompositor>(new VirtualCompositor());
}

std::string VirtualCompositor::get_serial() const
{
	return _serial;
}

void VirtualCompositor::update()
{
}

vr::TrackedDeviceIndex_t VirtualCompositor::get_index() const
{
	return _index;
}

void VirtualCompositor::process_event(const vr::VREvent_t & event)
{
}

vr::EVRInitError VirtualCompositor::Activate(vr::TrackedDeviceIndex_t index)
{
	_index = index;

	return vr::VRInitError_None;
}

void VirtualCompositor::Deactivate()
{
	// Clear device id
	_index = vr::k_unTrackedDeviceIndexInvalid;
}

void VirtualCompositor::EnterStandby()
{
}

void * VirtualCompositor::GetComponent(const char * component)
{
	if (std::string(component) == std::string(vr::IVRVirtualDisplay_Version))
	{
		return static_cast<vr::IVRVirtualDisplay*>(this);
	}
	return nullptr;
}

void VirtualCompositor::DebugRequest(const char * request, char * response_buffer, uint32_t response_buffer_size)
{
	// No custom debug requests defined
	if (response_buffer_size >= 1)
		response_buffer[0] = 0;
}

vr::DriverPose_t VirtualCompositor::GetPose()
{
	return vr::DriverPose_t();
}

void VirtualCompositor::Present(const vr::PresentInfo_t * present_info, uint32_t present_info_size)
{
	
}

void VirtualCompositor::WaitForPresent()
{
}

bool VirtualCompositor::GetTimeSinceLastVsync(float * seconds_since_last_vsync, uint64_t * frame_counter)
{
	return false;
}