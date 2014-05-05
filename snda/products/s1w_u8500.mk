# uperclass
$(call inherit-product, vendor/st-ericsson/products/ste_u8500.mk)

# Overrides
PRODUCT_NAME := s1w_u8500
PRODUCT_MODEL := Bambook S1
PRODUCT_BRAND := Bambookphone
PRODUCT_DEVICE := u8500
PRODUCT_MANUFACTURER := snda.com

PRODUCT_PROPERTY_OVERRIDES += \
    ro.sf.lcd_density=256 \
    persist.sys.timezone=Asia/Shanghai \
    persist.sys.language=zh \
    persist.sys.country=CN \

PRODUCT_PACKAGES += \
    e2fsck \
    libext2fs \
    libext2_blkid \
    libext2_uuid \
    libext2_profile \
    libext2_com_err \
    libext2_e2p

PRODUCT_PACKAGES += \
    SuperUser \

# charge resource
PRODUCT_COPY_FILES += \
    vendor/snda/s1_wu8500/charge-res/pic_0.rle:/system/usr/share/charge/res/pic_0.rle \
    vendor/snda/s1_wu8500/charge-res/pic_1.rle:/system/usr/share/charge/res/pic_1.rle \
    vendor/snda/s1_wu8500/charge-res/pic_2.rle:/system/usr/share/charge/res/pic_2.rle \
    vendor/snda/s1_wu8500/charge-res/pic_3.rle:/system/usr/share/charge/res/pic_3.rle \
    vendor/snda/s1_wu8500/charge-res/pic_4.rle:/system/usr/share/charge/res/pic_4.rle \
    vendor/snda/s1_wu8500/charge-res/pic_5.rle:/system/usr/share/charge/res/pic_5.rle \
    vendor/snda/s1_wu8500/charge-res/snda.rle:/system/usr/share/charge/res/snda.rle

DISPLAY_BUILD_NUMBER:=true

PRODUCT_PACKAGE_OVERLAYS := vendor/snda/overlay
