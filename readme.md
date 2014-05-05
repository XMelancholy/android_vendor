#Android 4.12

Getting Started :

		curl http://commondatastorage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
		chmod 755 ~/bin/repo
		mkdir cm11
		cd cm11
		repo init -u https://android.googlesource.com/platform/manifest -b android-4.1.2_r2.1
		repo sync

Now connect your phone which have runing AOSP 4.1.2 :

		git clone https://github.com/XMelancholy/android_vendor.git -b master vendor

		git clone https://github.com/XMelancholy/android_kernel_snda_u8500 -b master kernel/snda/u8500


Patch android source code :

		patch -p1 < vendor/snda/u8500/patches/build.patch



Our step is optional!!! Use only if you going to sync AOSP 4.1.2 source code daily, than simple revert each patch before you sync AOSP 4.1.2 source code :

		patch -p1 -R < vendor/snda/u8500/patches/build.patch
		repo forall -p -c 'git checkout -f'
		repo sync
		patch -p1 < vendor/snda/u8500/patches/build.patch


You are ready to build :

		source build/envsetup.sh
		lunch s1w_u8500-userdebug
		make otapackage

ENJOY!

