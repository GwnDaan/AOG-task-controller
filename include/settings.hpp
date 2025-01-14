/**
 * @author Daan Steenbergen
 * @brief An interface to store/load AOG-TC settings to/from a file
 * @version 0.1
 * @date 2025-1-14
 *
 * @copyright 2025 Daan Steenbergen
 */

#pragma once

#include <array>
#include <string>

class Settings
{
public:
	/**
     * @brief (re)load the settings from specified file
     * @return True if the settings were loaded successfully, false otherwise
     */
	bool load();

	/**
     * @brief Save the settings to specified file
     * @return True if the settings were saved successfully, false otherwise
     */
	bool save() const;

	/**
	 * @brief Get the configured subnet
	 * @return The configured subnet
	 */
	const std::array<std::uint8_t, 3> &get_subnet() const;

	/**
	 * @brief Set the configured subnet
	 * @param subnet The subnet to set
	 * @param save Whether or not to save the settings to file
	 * @return True if the subnet was set successfully, false otherwise
	 */
	bool set_subnet(std::array<std::uint8_t, 3> subnet, bool save = true);

private:
	/**
	 * @brief Get the absolute path to the settings file
	 * @return The absolute path to the settings file
	 */
	static std::string get_filename();

	constexpr static std::array<std::uint8_t, 3> DEFAULT_SUBNET = { 192, 168, 5 };
	std::array<std::uint8_t, 3> configuredSubnet = DEFAULT_SUBNET;
};
