PORTNAME=	pdfium
PORTVERSION=	7651
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
DISTFILES+=	9cce6259aef60f8dbea52f421bb0234eb7cdadd5.tar.gz:pa \
		26e5b4f1d8e96df200db4bf007961fd69f3d1168.tar.gz:build \
		4dc32b3f510b330137385e2b3a631ca8e13a8e22.tar.gz:buildtools \
		f78c65b71bd32a418584eee501ce419e3e71e1df.tar.gz:corpus \
		1597226b825a16493de66c1732171efe89b271d9.tar.gz:absl \
		c2725e0622e1a86d55f14514f2177a39efea4a0e.tar.gz:clangfmt \
		a4318057fe1f95e35d51d6b8e84b22717467e5d6.tar.gz:depot \
		beeeef91cf6fef89a4d4ba5e95d47ca64ccb3a44.tar.gz:dragonbox \
		cb1d42aaa1e14b09e1452cfdef373d051b8c02a4.tar.gz:fastfloat \
		3d2de1816307bac63c16a297e8c4dc501b4076df.tar.gz:fp16 \
		b91f75bd02db43b06d634591eb286d3eb0ce3b65.tar.gz:freetype \
		4fe3307fb2d9f86d19777c7eb0e4809e9694dde7.tar.gz:gtest \
		84379d1c73de9681b54fbe1c035a23c7bd5d272d.tar.gz:highway \
		a86a32e67b8d1384b33f8fa48c83a6079b86f8cd.tar.gz:icu \
		69015643b3f68dbd438c010439c59adc52cac808.tar.gz:instlib \
		c3027d884967773057bf74b957e3fea87e5df4d7.tar.gz:jinja2 \
		7ab65651aed6802d2599dcb7a73b1f82d5179d05.tar.gz:libcxx \
		8f11bb1d4438d0239d0dfc1bd9456a9f31629dda.tar.gz:libcxxabi \
		6bb85251a8382b5e07f635a981ac685cc5ab5053.tar.gz:jpeg \
		f63f5ef0e0ef0f17645c015568b729e452e57147.tar.gz:png \
		4d1d71696f4c33f218b9969ef698a1d57833bdf9.tar.gz:llvm_libc \
		4256084ae14175d38a3ff7d739dca83ae49ccec6.tar.gz:markupsafe \
		af5eeeb054bebadfbb79c7bcd100a95e2ad4525f.tar.gz:nasm \
		75bea7342fdac6b57f7e3099ddf4dc84d77384f6.tar.gz:simdutf \
		2e253c215286f0c973302b86f70f3120d7172616.tar.gz:skia \
		7f51783942943e965cd56facf786544ccfc07713.tar.gz:testfonts \
		e00f7038713ff2e751c28a1ac08f0b68bca8567c.tar.gz:zlib \
		5ec0da997c0a1d60358230aad6d2e4d779c28668.tar.gz:tools_clang \
		fc75c61d3a98a78ff83940366aeba83ddeb28179.tar.gz:codecov \
		16429092be4bb5160bed0ad763bd4c13f1f52990.tar.gz:tools_mem \
		ce8c1a51ccaf2852af891fbf6bb33646b61665d2.tar.gz:v8
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

_DEPS_DIRS=	base/allocator/partition_allocator:9cce6259aef60f8dbea52f421bb0234eb7cdadd5 \
		build:26e5b4f1d8e96df200db4bf007961fd69f3d1168 \
		buildtools:4dc32b3f510b330137385e2b3a631ca8e13a8e22 \
		testing/corpus:f78c65b71bd32a418584eee501ce419e3e71e1df \
		third_party/abseil-cpp:1597226b825a16493de66c1732171efe89b271d9 \
		third_party/clang-format/script:c2725e0622e1a86d55f14514f2177a39efea4a0e \
		third_party/depot_tools:a4318057fe1f95e35d51d6b8e84b22717467e5d6 \
		third_party/dragonbox/src:beeeef91cf6fef89a4d4ba5e95d47ca64ccb3a44 \
		third_party/fast_float/src:cb1d42aaa1e14b09e1452cfdef373d051b8c02a4 \
		third_party/fp16/src:3d2de1816307bac63c16a297e8c4dc501b4076df \
		third_party/freetype/src:b91f75bd02db43b06d634591eb286d3eb0ce3b65 \
		third_party/googletest/src:4fe3307fb2d9f86d19777c7eb0e4809e9694dde7 \
		third_party/highway/src:84379d1c73de9681b54fbe1c035a23c7bd5d272d \
		third_party/icu:a86a32e67b8d1384b33f8fa48c83a6079b86f8cd \
		third_party/instrumented_libs:69015643b3f68dbd438c010439c59adc52cac808 \
		third_party/jinja2:c3027d884967773057bf74b957e3fea87e5df4d7 \
		third_party/libc++/src:7ab65651aed6802d2599dcb7a73b1f82d5179d05 \
		third_party/libc++abi/src:8f11bb1d4438d0239d0dfc1bd9456a9f31629dda \
		third_party/libjpeg_turbo:6bb85251a8382b5e07f635a981ac685cc5ab5053 \
		third_party/libpng:f63f5ef0e0ef0f17645c015568b729e452e57147 \
		third_party/llvm-libc/src:4d1d71696f4c33f218b9969ef698a1d57833bdf9 \
		third_party/markupsafe:4256084ae14175d38a3ff7d739dca83ae49ccec6 \
		third_party/nasm:af5eeeb054bebadfbb79c7bcd100a95e2ad4525f \
		third_party/simdutf:75bea7342fdac6b57f7e3099ddf4dc84d77384f6 \
		third_party/skia:2e253c215286f0c973302b86f70f3120d7172616 \
		third_party/test_fonts:7f51783942943e965cd56facf786544ccfc07713 \
		third_party/zlib:e00f7038713ff2e751c28a1ac08f0b68bca8567c \
		tools/clang:5ec0da997c0a1d60358230aad6d2e4d779c28668 \
		tools/code_coverage:fc75c61d3a98a78ff83940366aeba83ddeb28179 \
		tools/memory:16429092be4bb5160bed0ad763bd4c13f1f52990 \
		v8:ce8c1a51ccaf2852af891fbf6bb33646b61665d2

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

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/pdfium/cpp
	${INSTALL_LIB} ${WRKSRC}/${GN_OUT}/obj/libpdfium.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/public/*.h ${STAGEDIR}${PREFIX}/include/pdfium/
	${INSTALL_DATA} ${WRKSRC}/public/cpp/*.h ${STAGEDIR}${PREFIX}/include/pdfium/cpp/

.include <bsd.port.mk>
