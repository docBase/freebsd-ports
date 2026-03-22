PORTNAME=	pdfium
PORTVERSION=	7746
CATEGORIES=	graphics
# Additional DEPS tarballs required for a full FreeBSD build.
MASTER_SITES+=	https://chromium.googlesource.com/chromium/src/base/allocator/partition_allocator/+archive/:pa \
		https://chromium.googlesource.com/chromium/src/build/+archive/:build \
		https://chromium.googlesource.com/chromium/src/buildtools/+archive/:buildtools \
		https://pdfium.googlesource.com/pdfium_tests/+archive/:corpus \
		https://chromium.googlesource.com/chromium/src/third_party/abseil-cpp/+archive/:absl \
		https://chromium.googlesource.com/external/github.com/llvm/llvm-project/clang/tools/clang-format/+archive/:clangfmt \
		https://chromium.googlesource.com/chromium/tools/depot_tools/+archive/:depot \
		https://chromium.googlesource.com/external/github.com/jk-jeon/dragonbox/+archive/:dragonbox \
		https://chromium.googlesource.com/external/github.com/fastfloat/fast_float/+archive/:fastfloat \
		https://chromium.googlesource.com/external/github.com/Maratyszcza/FP16/+archive/:fp16 \
		https://chromium.googlesource.com/chromium/src/third_party/freetype2/+archive/:freetype \
		https://chromium.googlesource.com/external/github.com/google/googletest/+archive/:gtest \
		https://chromium.googlesource.com/external/github.com/google/highway/+archive/:highway \
		https://chromium.googlesource.com/chromium/deps/icu/+archive/:icu \
		https://chromium.googlesource.com/chromium/third_party/instrumented_libraries/+archive/:instlib \
		https://chromium.googlesource.com/chromium/src/third_party/jinja2/+archive/:jinja2 \
		https://chromium.googlesource.com/external/github.com/llvm/llvm-project/libcxx/+archive/:libcxx \
		https://chromium.googlesource.com/external/github.com/llvm/llvm-project/libcxxabi/+archive/:libcxxabi \
		https://chromium.googlesource.com/chromium/deps/libjpeg_turbo/+archive/:jpeg \
		https://chromium.googlesource.com/chromium/src/third_party/libpng/+archive/:png \
		https://chromium.googlesource.com/external/github.com/llvm/llvm-project/libc/+archive/:llvm_libc \
		https://chromium.googlesource.com/chromium/src/third_party/markupsafe/+archive/:markupsafe \
		https://chromium.googlesource.com/chromium/deps/nasm/+archive/:nasm \
		https://chromium.googlesource.com/chromium/src/third_party/simdutf/+archive/:simdutf \
		https://skia.googlesource.com/skia/+archive/:skia \
		https://chromium.googlesource.com/chromium/src/third_party/test_fonts/+archive/:testfonts \
		https://chromium.googlesource.com/chromium/src/third_party/zlib/+archive/:zlib \
		https://chromium.googlesource.com/chromium/src/tools/clang/+archive/:tools_clang \
		https://chromium.googlesource.com/chromium/src/tools/code_coverage/+archive/:codecov \
		https://chromium.googlesource.com/chromium/src/tools/memory/+archive/:tools_mem \
		https://chromium.googlesource.com/v8/v8/+archive/:v8
DISTFILES+=	2157c84d9a0d075c1ca31cc120590a9743550647.tar.gz:pa \
		c9202dd8ca1d4255bd9e505988b945746ddb378a.tar.gz:build \
		fef8d6947fa54202e8a00c58d5ac8fd15780bc33.tar.gz:buildtools \
		282089c64969a79e8d32b35b5ef27e3bc64f092b.tar.gz:corpus \
		2a7d49fc392cad55159d68d98aa3648bc89795d3.tar.gz:absl \
		c2725e0622e1a86d55f14514f2177a39efea4a0e.tar.gz:clangfmt \
		55659c2bf434a4fb508799fa93550822c5309ed5.tar.gz:depot \
		beeeef91cf6fef89a4d4ba5e95d47ca64ccb3a44.tar.gz:dragonbox \
		cb1d42aaa1e14b09e1452cfdef373d051b8c02a4.tar.gz:fastfloat \
		3d2de1816307bac63c16a297e8c4dc501b4076df.tar.gz:fp16 \
		99b479dc34728936b006679a31e12b8cf432fc55.tar.gz:freetype \
		4fe3307fb2d9f86d19777c7eb0e4809e9694dde7.tar.gz:gtest \
		84379d1c73de9681b54fbe1c035a23c7bd5d272d.tar.gz:highway \
		a86a32e67b8d1384b33f8fa48c83a6079b86f8cd.tar.gz:icu \
		e8cb570a9a2ee9128e2214c73417ad2a3c47780b.tar.gz:instlib \
		c3027d884967773057bf74b957e3fea87e5df4d7.tar.gz:jinja2 \
		7ab65651aed6802d2599dcb7a73b1f82d5179d05.tar.gz:libcxx \
		8f11bb1d4438d0239d0dfc1bd9456a9f31629dda.tar.gz:libcxxabi \
		d1f5f2393e0d51f840207342ae86e55a86443288.tar.gz:jpeg \
		367bb5ca4af50342f709f444af04002527ce8b0f.tar.gz:png \
		044963a253be3b8b2a63a1b2e0f3e361b01bc186.tar.gz:llvm_libc \
		4256084ae14175d38a3ff7d739dca83ae49ccec6.tar.gz:markupsafe \
		af5eeeb054bebadfbb79c7bcd100a95e2ad4525f.tar.gz:nasm \
		f7356eed293f8208c40b3c1b344a50bd70971983.tar.gz:simdutf \
		90b1d0b22a61f554629aef1f2765d816d5d2e217.tar.gz:skia \
		7f51783942943e965cd56facf786544ccfc07713.tar.gz:testfonts \
		7eda07b1e067ef3fd7eea0419c88b5af45c9a776.tar.gz:zlib \
		c5563f5d680277c5e0e46daef3b7b0594f27ee94.tar.gz:tools_clang \
		839c826036d49abbc58e67f740dc48d7e2d757da.tar.gz:codecov \
		b635f27e932356a2e29450e5cfa544cdcc9ea6bb.tar.gz:tools_mem \
		b210c794d22b5c0839ad63d8ae9129d6062168da.tar.gz:v8
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	matias@pizarro.net
COMMENT=	PDF rendering and manipulation library
WWW=		https://pdfium.googlesource.com/pdfium/

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gn:devel/gn \
		llvm19>=19:devel/llvm19 \
		ninja:devel/ninja

USES=		compiler:c++20-lang pkgconfig python:build
USE_GITHUB=	yes
GH_ACCOUNT=	matias-pizarro

# Gitiles archives can vary in gzip headers; normalize in pre-checksum.
.ifnmake portclippy
DISABLE_SIZE=	yes
.endif

GN_OUT=		out/Release
GN_ARGS=	is_debug=false \
		is_component_build=false \
		pdf_is_complete_lib=true \
		pdf_is_standalone=false \
		pdf_enable_v8=false \
		pdf_enable_xfa=false \
		clang_use_chrome_plugins=false \
		use_sysroot=false \
		use_custom_libcxx=false \
		use_custom_libcxx_for_host=false \
		treat_warnings_as_errors=false \
		clang_base_path="${LOCALBASE}/llvm19" \
		clang_version="19"

_DEPS_DIRS=	base/allocator/partition_allocator:2157c84d9a0d075c1ca31cc120590a9743550647 \
		build:c9202dd8ca1d4255bd9e505988b945746ddb378a \
		buildtools:fef8d6947fa54202e8a00c58d5ac8fd15780bc33 \
		testing/corpus:282089c64969a79e8d32b35b5ef27e3bc64f092b \
		third_party/abseil-cpp:2a7d49fc392cad55159d68d98aa3648bc89795d3 \
		third_party/clang-format/script:c2725e0622e1a86d55f14514f2177a39efea4a0e \
		third_party/depot_tools:55659c2bf434a4fb508799fa93550822c5309ed5 \
		third_party/dragonbox/src:beeeef91cf6fef89a4d4ba5e95d47ca64ccb3a44 \
		third_party/fast_float/src:cb1d42aaa1e14b09e1452cfdef373d051b8c02a4 \
		third_party/fp16/src:3d2de1816307bac63c16a297e8c4dc501b4076df \
		third_party/freetype/src:99b479dc34728936b006679a31e12b8cf432fc55 \
		third_party/googletest/src:4fe3307fb2d9f86d19777c7eb0e4809e9694dde7 \
		third_party/highway/src:84379d1c73de9681b54fbe1c035a23c7bd5d272d \
		third_party/icu:a86a32e67b8d1384b33f8fa48c83a6079b86f8cd \
		third_party/instrumented_libs:e8cb570a9a2ee9128e2214c73417ad2a3c47780b \
		third_party/jinja2:c3027d884967773057bf74b957e3fea87e5df4d7 \
		third_party/libc++/src:7ab65651aed6802d2599dcb7a73b1f82d5179d05 \
		third_party/libc++abi/src:8f11bb1d4438d0239d0dfc1bd9456a9f31629dda \
		third_party/libjpeg_turbo:d1f5f2393e0d51f840207342ae86e55a86443288 \
		third_party/libpng:367bb5ca4af50342f709f444af04002527ce8b0f \
		third_party/llvm-libc/src:044963a253be3b8b2a63a1b2e0f3e361b01bc186 \
		third_party/markupsafe:4256084ae14175d38a3ff7d739dca83ae49ccec6 \
		third_party/nasm:af5eeeb054bebadfbb79c7bcd100a95e2ad4525f \
		third_party/simdutf:f7356eed293f8208c40b3c1b344a50bd70971983 \
		third_party/skia:90b1d0b22a61f554629aef1f2765d816d5d2e217 \
		third_party/test_fonts:7f51783942943e965cd56facf786544ccfc07713 \
		third_party/zlib:7eda07b1e067ef3fd7eea0419c88b5af45c9a776 \
		tools/clang:c5563f5d680277c5e0e46daef3b7b0594f27ee94 \
		tools/code_coverage:839c826036d49abbc58e67f740dc48d7e2d757da \
		tools/memory:b635f27e932356a2e29450e5cfa544cdcc9ea6bb \
		v8:b210c794d22b5c0839ad63d8ae9129d6062168da

pre-checksum:
.for dep in ${_DEPS_DIRS}
	@${GUNZIP_CMD} -c ${DISTDIR}/${dep:C/^.*://}.tar.gz | ${GZIP_CMD} -n > ${DISTDIR}/${dep:C/^.*://}.tar.gz.tmp
	@${MV} ${DISTDIR}/${dep:C/^.*://}.tar.gz.tmp ${DISTDIR}/${dep:C/^.*://}.tar.gz
.endfor

post-extract:
.for dep in ${_DEPS_DIRS}
	@${MKDIR} ${WRKSRC}/${dep:C/:.*//}
	@${TAR} -xf ${DISTDIR}/${dep:C/^.*://}.tar.gz -C ${WRKSRC}/${dep:C/:.*//}
.endfor

do-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/gn gen ${GN_OUT} --args='${GN_ARGS}'

do-build:
	cd ${WRKSRC} && ${LOCALBASE}/bin/ninja -C ${GN_OUT} pdfium
	@${ECHO_MSG} "===> Building shared library from static archive"
	cd ${WRKSRC} && ${LOCALBASE}/llvm19/bin/clang++ -shared \
		-o ${GN_OUT}/obj/libpdfium.so \
		-Wl,--whole-archive ${GN_OUT}/obj/libpdfium.a \
		-Wl,--no-whole-archive -lstdc++ -lm

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/pdfium/cpp
	${INSTALL_LIB} ${WRKSRC}/${GN_OUT}/obj/libpdfium.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/${GN_OUT}/obj/libpdfium.so ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/public/*.h ${STAGEDIR}${PREFIX}/include/pdfium/
	${INSTALL_DATA} ${WRKSRC}/public/cpp/*.h ${STAGEDIR}${PREFIX}/include/pdfium/cpp/

.include <bsd.port.mk>
