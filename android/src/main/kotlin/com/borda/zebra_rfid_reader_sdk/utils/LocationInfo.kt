package com.borda.zebra_rfid_reader_sdk.utils

class LocationInfo {
    private var tag: String? = null
    private var distanceAsPercentage: Int? = null

    constructor(tag: String?, distanceAsPercentage: Int?) {
        this.tag = tag
        this.distanceAsPercentage = distanceAsPercentage
    }
}