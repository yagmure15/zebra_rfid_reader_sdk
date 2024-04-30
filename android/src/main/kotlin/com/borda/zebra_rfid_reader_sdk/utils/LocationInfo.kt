package com.borda.zebra_rfid_reader_sdk.utils

class LocationInfo {
    private var tag: String? = null
    private var distanceAsPercentage: Int? = null
    private var isAnyReaderConnected: Boolean? = null

    constructor(tag: String?, distanceAsPercentage: Int?,isAnyReaderConnected: Boolean? ) {
        this.tag = tag
        this.distanceAsPercentage = distanceAsPercentage
        this.isAnyReaderConnected = isAnyReaderConnected
    }
}