MMC_OBJECTS += $(BUILD_DIR)drivers/mmc/sdcard.o
MMC_OBJECTS-$(BT_CONFIG_DRIVERS_SDCARD_HOST_SDHCI) += $(BUILD_DIR)drivers/mmc/host/sdhci.o


MMC_OBJECTS += $(MMC_OBJECTS-y)

$(MMC_OBJECTS): MODULE_NAME="drivers-SDIO"


OBJECTS += $(MMC_OBJECTS)