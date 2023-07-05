#pragma once
#include <cstdint>
#include <cstddef>
#include <iostream>
#include "memory.h"
#include "offsets.h"

using namespace std;

int main()
{
	// initialize memory class
	const auto memory = Memory{ "csgo.exe" };

	// module address's - only "client.dll" is needed
	const auto client = memory.GetModuleAddress("client.dll");
	const auto engine = memory.GetModuleAddress("engine.dll");
	int fov; 

	while (true)
	{
		// read memory of client.dll + dwLocalPlayer offset set it to "localPlayer"
		const auto& localPlayer = memory.Read<std::uintptr_t>(client + offset::dwLocalPlayer);

		// user input for new FOV
		cout << "Please enter your desired FOV: ";
		cin >> fov;
		cout << endl << "Your new FOV is: " << fov << "! " << endl << endl;

		// now write into processes memory new FOV value	
		memory.Write<int>(localPlayer + offset::m_iDefaultFOV, fov);


		// done! simple external working FOV Changer, you can add this code to an imgui project to take to fov input as a slider! discord: aidencpp  ----> feel free to add me for any questions relating to this program! :)
	}
}