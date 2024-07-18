package com.borda.zebra_rfid_reader_sdk.utils

import com.google.gson.annotations.SerializedName

class LocationInfo {
    @SerializedName("tag")
    private var tag: String? = null
    @SerializedName("distanceAsPercentage")
    private var distanceAsPercentage: Int? = null
    @SerializedName("isAnyReaderConnected")
    private var isAnyReaderConnected: Boolean? = null

    constructor(tag: String?, distanceAsPercentage: Int?,isAnyReaderConnected: Boolean? ) {
        this.tag = tag
        this.distanceAsPercentage = distanceAsPercentage
        this.isAnyReaderConnected = isAnyReaderConnected
    }
}