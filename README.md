# ModernStandbyStart

Simple utility that, when launched, sends a `WM_SYSCOMMAND` window message with the `SC_MONITORPOWER` parameter to turn off the screen. This allows the Modern Standby mode of Windows to be activated, which is not possible with any of the built-in system utilities.
This tool is useful for creating scripts or key macros that involve triggering the Modern Standby mode.

# Building / Binaries

The tool can be built using Visual Studio 2022, but, due to its simple nature, the code should compile with most VS versions.
Pre-built binaries for x86 and x64 are also available from the GitHub release.
