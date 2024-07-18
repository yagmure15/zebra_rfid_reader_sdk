package com.borda.zebra_rfid_reader_sdk.utils

import com.google.gson.annotations.SerializedName

/**
 * Represents a single Borda reader device, encapsulating its connection status, name, and battery level.
 *
 * @property connectionStatus The connection status of the reader.
 * @property name The name of the reader (optional).
 * @property batteryLevel The battery level of the reader (optional).
 */
class BordaReaderDevice {
    @SerializedName("connectionStatus")
    private var connectionStatus: ConnectionStatus = ConnectionStatus.notConnected
    @SerializedName("name")
    private var name: String? = null
    @SerializedName("batteryLevel")
    private var batteryLevel: String? = null
    @SerializedName("antennaRange")
    private var antennaRange: IntArray? = null

    constructor(connectionStatus: ConnectionStatus, name: String?, batteryLevel: String?, antennaRange: IntArray?) {
        this.connectionStatus = connectionStatus
        this.name = name
        this.batteryLevel = batteryLevel
        this.antennaRange = antennaRange
    }
}