package com.borda.zebra_rfid_reader_sdk.utils

object  BordaHandheldTrigger {
    private var mode: TriggerMode = TriggerMode.INVENTORY_PERFORM

    fun setMode(triggerMode: TriggerMode) {
        this.mode = triggerMode
    }

    fun getMode(): TriggerMode {
        return mode
    }
}