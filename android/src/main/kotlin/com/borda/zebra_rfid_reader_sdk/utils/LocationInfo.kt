package com.borda.zebra_rfid_reader_sdk.utils

class LocationInfo {
    private var location: String? = null
    private var distancePercent: Int? = null

    constructor(location: String?, distancePercent: Int?) {
        this.location = location
        this.distancePercent = distancePercent
    }
}