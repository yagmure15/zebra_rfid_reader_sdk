package com.borda.zebra_rfid_reader_sdk.utils

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