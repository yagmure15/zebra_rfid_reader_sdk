package com.borda.zebra_rfid_reader_sdk.utils

import com.google.gson.Gson

object TagLocationingResponse {
    private var tag: String = ""
    private var distancePercent: Int? = null
    private var isAnyReaderConnected: Boolean = false


    fun setTag(tag: String) {
        this.tag = tag
    }

    fun getTag(): String {
        return tag
    }

    fun setAnyReaderConnected(isAnyReaderConnected: Boolean) {
        this.isAnyReaderConnected = isAnyReaderConnected
    }

    fun setDistancePercent(distancePercent: Int?) {
        this.distancePercent = distancePercent
    }

    fun reset() {
        this.tag = ""
        this.isAnyReaderConnected = false
        this.distancePercent = null
    }

    fun toJson(): String {
        return Gson().toJson(LocationInfo(tag, distancePercent, isAnyReaderConnected))
    }

}