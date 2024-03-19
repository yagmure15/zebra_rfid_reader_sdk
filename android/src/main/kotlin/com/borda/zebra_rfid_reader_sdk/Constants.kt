package com.borda.zebra_rfid_reader_sdk


import android.util.Log
import com.google.gson.Gson

const val LOG_TAG = "ZEBRA_RFID_READER_SDK"

/**
 * Represents a single Borda reader device, encapsulating its connection status, name, and battery level.
 *
 * @property connectionStatus The connection status of the reader.
 * @property name The name of the reader (optional).
 * @property batteryLevel The battery level of the reader (optional).
 */
class BordaReaderDevice {
    private var connectionStatus: ConnectionStatus = ConnectionStatus.notConnected
    private var name: String? = null
    private var batteryLevel: String? = null

    constructor(connectionStatus: ConnectionStatus, name: String?, batteryLevel: String?) {
        this.connectionStatus = connectionStatus
        this.name = name
        this.batteryLevel = batteryLevel
    }
}

/**
 * This class manages the reader response data, including connection status,
 * name, and battery level. It provides methods to update and retrieve this data
 * in a JSON format suitable for sending to the Flutter side.
 *
 * @property connectionStatus The connection status of the reader.
 * @property name The name of the reader.
 * @property batteryLevel The battery level of the reader.
 */
object ReaderResponse {
    private var connectionStatus: ConnectionStatus = ConnectionStatus.notConnected
    private var name: String? = null
    private var batteryLevel: String? = null

    /**
     * Update the reader connection status
     *
     * @param connectionStatus
     */
    fun setConnectionStatus(connectionStatus: ConnectionStatus) {
        this.connectionStatus = connectionStatus
    }

    /**
     * Update the reader name
     *
     * @param name
     */
    fun setName(name: String?) {
        this.name = name
    }

    /**
     * Update the battery level
     *
     * @param batteryLevel
     */
    fun setBatteryLevel(batteryLevel: String?) {
        this.batteryLevel = batteryLevel
    }

    /**
     * Resets all reader response properties to their initial values.
     */
    fun reset() {
        this.batteryLevel = null
        this.connectionStatus = ConnectionStatus.notConnected
        this.name = null
    }
    /**
     * Sets the connection status to "failed".
     */
    fun setAsConnectionError() {
        this.batteryLevel = null
        this.connectionStatus = ConnectionStatus.failed
    }

    /**
     *  Return the existing singleton object itself
     */
    fun toJson(): String {
        return Gson().toJson(BordaReaderDevice(connectionStatus, name, batteryLevel))
    }
}

enum class ConnectionStatus {
    notConnected, connecting, connected, failed
}
