PORTNAME=	pulumi-plugins-command
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	devel

MAINTAINER=	matias@pizarro.net
COMMENT=	Pulumi Command Resource Provider
WWW=		https://github.com/pulumi/pulumi-command

LICENSE=	APACHE20

BUILD_DEPENDS=	pulumi:devel/pulumi
RUN_DEPENDS=	pulumi:devel/pulumi

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	pulumi
GH_PROJECT=	pulumi-command
GH_TUPLE=	Microsoft:go-winio:v0.6.2:microsoft_go_winio/provider/vendor/github.com/Microsoft/go-winio \
		ProtonMail:go-crypto:v1.2.0:protonmail_go_crypto/provider/vendor/github.com/ProtonMail/go-crypto \
		agext:levenshtein:v1.2.3:agext_levenshtein/provider/vendor/github.com/agext/levenshtein \
		anmitsu:go-shlex:38f4b401e2be:anmitsu_go_shlex/provider/vendor/github.com/anmitsu/go-shlex \
		apparentlymart:go-textseg:v15.0.0:apparentlymart_go_textseg_v15/provider/vendor/github.com/apparentlymart/go-textseg/v15 \
		atotto:clipboard:v0.1.4:atotto_clipboard/provider/vendor/github.com/atotto/clipboard \
		aymanbagabas:go-osc52:v2.0.1:aymanbagabas_go_osc52_v2/provider/vendor/github.com/aymanbagabas/go-osc52/v2 \
		blang:semver:v3.5.1:blang_semver/provider/vendor/github.com/blang/semver \
		cenkalti:backoff:v5.0.3:cenkalti_backoff_v5/provider/vendor/github.com/cenkalti/backoff/v5 \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/provider/vendor/github.com/cespare/xxhash/v2 \
		charmbracelet:bubbles:v1.0.0:charmbracelet_bubbles/provider/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v1.3.10:charmbracelet_bubbletea/provider/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:colorprofile:v0.4.2:charmbracelet_colorprofile/provider/vendor/github.com/charmbracelet/colorprofile \
		charmbracelet:lipgloss:v1.1.0:charmbracelet_lipgloss/provider/vendor/github.com/charmbracelet/lipgloss \
		charmbracelet:x:ansi/v0.11.6:charmbracelet_x_ansi \
		charmbracelet:x:cellbuf/v0.0.15:charmbracelet_x_cellbuf \
		charmbracelet:x:term/v0.2.2:charmbracelet_x_term/provider/vendor/github.com/charmbracelet/x \
		cheggaaa:pb:v1.0.29:cheggaaa_pb/provider/vendor/github.com/cheggaaa/pb \
		clipperhouse:displaywidth:v0.11.0:clipperhouse_displaywidth/provider/vendor/github.com/clipperhouse/displaywidth \
		clipperhouse:uax29:v2.7.0:clipperhouse_uax29_v2/provider/vendor/github.com/clipperhouse/uax29/v2 \
		cloudflare:circl:v1.6.3:cloudflare_circl/provider/vendor/github.com/cloudflare/circl \
		cyphar:filepath-securejoin:v0.4.1:cyphar_filepath_securejoin/provider/vendor/github.com/cyphar/filepath-securejoin \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/provider/vendor/github.com/davecgh/go-spew \
		djherbis:times:v1.6.0:djherbis_times/provider/vendor/github.com/djherbis/times \
		edsrzf:mmap-go:v1.2.0:edsrzf_mmap_go/provider/vendor/github.com/edsrzf/mmap-go \
		emirpasic:gods:v1.18.1:emirpasic_gods/provider/vendor/github.com/emirpasic/gods \
		erikgeiser:coninput:1c3628e74d0f:erikgeiser_coninput/provider/vendor/github.com/erikgeiser/coninput \
		gliderlabs:ssh:v0.3.8:gliderlabs_ssh/provider/vendor/github.com/gliderlabs/ssh \
		go-git:gcfg:3a3c6141e376:go_git_gcfg/provider/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.6.2:go_git_go_billy_v5/provider/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.16.5:go_git_go_git_v5/provider/vendor/github.com/go-git/go-git/v5 \
		go-logr:logr:v1.4.3:go_logr_logr/provider/vendor/github.com/go-logr/logr \
		go-logr:stdr:v1.2.2:go_logr_stdr/provider/vendor/github.com/go-logr/stdr \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/provider/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/provider/vendor/gopkg.in/yaml.v3 \
		gobwas:glob:v0.2.3:gobwas_glob/provider/vendor/github.com/gobwas/glob \
		gogo:protobuf:v1.3.2:gogo_protobuf/provider/vendor/github.com/gogo/protobuf \
		golang:crypto:v0.48.0:golang_crypto/provider/vendor/golang.org/x/crypto \
		golang:exp:645b1fa84792:golang_exp/provider/vendor/golang.org/x/exp \
		golang:glog:v1.2.5:golang_glog/provider/vendor/github.com/golang/glog \
		golang:groupcache:2c02b8208cf8:golang_groupcache/provider/vendor/github.com/golang/groupcache \
		golang:mod:v0.32.0:golang_mod/provider/vendor/golang.org/x/mod \
		golang:net:v0.51.0:golang_net/provider/vendor/golang.org/x/net \
		golang:protobuf:v1.5.4:golang_protobuf/provider/vendor/github.com/golang/protobuf \
		golang:sync:v0.19.0:golang_sync/provider/vendor/golang.org/x/sync \
		golang:sys:v0.41.0:golang_sys/provider/vendor/golang.org/x/sys \
		golang:term:v0.40.0:golang_term/provider/vendor/golang.org/x/term \
		golang:text:v0.34.0:golang_text/provider/vendor/golang.org/x/text \
		golang:tools:v0.41.0:golang_tools/provider/vendor/golang.org/x/tools \
		google:go-genproto:2f722ef697dc:google_go_genproto/provider/vendor/google.golang.org/genproto \
		google:uuid:v1.6.0:google_uuid/provider/vendor/github.com/google/uuid \
		grpc-ecosystem:grpc-gateway:v2.28.0:grpc_ecosystem_grpc_gateway_v2/provider/vendor/github.com/grpc-ecosystem/grpc-gateway/v2 \
		grpc-ecosystem:grpc-opentracing:8e809c8a8645:grpc_ecosystem_grpc_opentracing/provider/vendor/github.com/grpc-ecosystem/grpc-opentracing \
		grpc:grpc-go:v1.79.1:grpc_grpc_go/provider/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/provider/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/provider/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-version:v1.8.0:hashicorp_go_version/provider/vendor/github.com/hashicorp/go-version \
		hashicorp:hcl:v2.23.0:hashicorp_hcl_v2/provider/vendor/github.com/hashicorp/hcl/v2 \
		imdario:mergo:v1.0.1:imdario_mergo/provider/vendor/dario.cat/mergo \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/provider/vendor/github.com/inconshreveable/mousetrap \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/provider/vendor/github.com/jbenet/go-context \
		json-iterator:go:v1.1.12:json_iterator_go/provider/vendor/github.com/json-iterator/go \
		kevinburke:ssh_config:v1.2.0:kevinburke_ssh_config/provider/vendor/github.com/kevinburke/ssh_config \
		klauspost:compress:v1.18.0:klauspost_compress/provider/vendor/github.com/klauspost/compress \
		kr:fs:v0.1.0:kr_fs/provider/vendor/github.com/kr/fs \
		lucasb-eyer:go-colorful:v1.3.0:lucasb_eyer_go_colorful/provider/vendor/github.com/lucasb-eyer/go-colorful \
		lukechampine:frand:v1.5.1:lukechampine_frand/provider/vendor/lukechampine.com/frand \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/provider/vendor/github.com/mattn/go-isatty \
		mattn:go-localereader:v0.0.1:mattn_go_localereader/provider/vendor/github.com/mattn/go-localereader \
		mattn:go-runewidth:v0.0.20:mattn_go_runewidth/provider/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-ps:v1.0.0:mitchellh_go_ps/provider/vendor/github.com/mitchellh/go-ps \
		mitchellh:go-wordwrap:v1.0.1:mitchellh_go_wordwrap/provider/vendor/github.com/mitchellh/go-wordwrap \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/provider/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:35a7c28c31ee:modern_go_reflect2/provider/vendor/github.com/modern-go/reflect2 \
		muesli:ansi:276c6243b2f6:muesli_ansi/provider/vendor/github.com/muesli/ansi \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/provider/vendor/github.com/muesli/cancelreader \
		muesli:termenv:v0.16.0:muesli_termenv/provider/vendor/github.com/muesli/termenv \
		natefinch:atomic:v1.0.1:natefinch_atomic/provider/vendor/github.com/natefinch/atomic \
		open-telemetry:opentelemetry-collector:featuregate/v1.52.0:otel_collector/provider/vendor/go.opentelemetry.io/collector \
		open-telemetry:opentelemetry-go:v1.40.0:otel_go/provider/vendor/go.opentelemetry.io/otel \
		open-telemetry:opentelemetry-go-instrumentation:sdk/v1.2.1:otel_auto/provider/vendor/go.opentelemetry.io/auto \
		open-telemetry:opentelemetry-proto-go:otlp/v1.9.0:otel_proto/provider/vendor/go.opentelemetry.io/proto \
		opentracing:basictracer-go:v1.1.0:opentracing_basictracer_go/provider/vendor/github.com/opentracing/basictracer-go \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/provider/vendor/github.com/opentracing/opentracing-go \
		pgavlin:fx:v0.1.6:pgavlin_fx/provider/vendor/github.com/pgavlin/fx \
		pgavlin:fx:v2.0.10:pgavlin_fx_v2/provider/vendor/github.com/pgavlin/fx/v2 \
		pgavlin:goldmark:b5eb04559386:pgavlin_goldmark/provider/vendor/github.com/pgavlin/goldmark \
		pjbgf:sha1cd:v0.3.2:pjbgf_sha1cd/provider/vendor/github.com/pjbgf/sha1cd \
		pkg:errors:v0.9.1:pkg_errors/provider/vendor/github.com/pkg/errors \
		pkg:sftp:v1.13.6:pkg_sftp/provider/vendor/github.com/pkg/sftp \
		pkg:term:v1.2.0-beta.2:pkg_term/provider/vendor/github.com/pkg/term \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/provider/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.36.11:protocolbuffers_protobuf_go/provider/vendor/google.golang.org/protobuf \
		pulumi:appdash:75f619a67231:pulumi_appdash/provider/vendor/github.com/pulumi/appdash \
		pulumi:esc:v0.22.0:pulumi_esc/provider/vendor/github.com/pulumi/esc \
		pulumi:pulumi-go-provider:v1.3.0:pulumi_pulumi_go_provider/provider/vendor/github.com/pulumi/pulumi-go-provider \
		pulumi:pulumi:sdk/v3.224.0:pulumi_pulumi_sdk \
		pulumi:pulumi:pkg/v3.224.0:pulumi_pulumi_pkg \
		rivo:uniseg:v0.4.7:rivo_uniseg/provider/vendor/github.com/rivo/uniseg \
		rogpeppe:go-internal:v1.14.1:rogpeppe_go_internal/provider/vendor/github.com/rogpeppe/go-internal \
		sabhiram:go-gitignore:525f6e181f06:sabhiram_go_gitignore/provider/vendor/github.com/sabhiram/go-gitignore \
		santhosh-tekuri:jsonschema:v5.3.1:santhosh_tekuri_jsonschema_v5/provider/vendor/github.com/santhosh-tekuri/jsonschema/v5 \
		segmentio:asm:v1.2.0:segmentio_asm/provider/vendor/github.com/segmentio/asm \
		segmentio:encoding:v0.4.1:segmentio_encoding/provider/vendor/github.com/segmentio/encoding \
		sergi:go-diff:v1.4.0:sergi_go_diff/provider/vendor/github.com/sergi/go-diff \
		skeema:knownhosts:v1.3.1:skeema_knownhosts/provider/vendor/github.com/skeema/knownhosts \
		spf13:cobra:v1.10.2:spf13_cobra/provider/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.10:spf13_pflag/provider/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.11.1:stretchr_testify/provider/vendor/github.com/stretchr/testify \
		texttheater:golang-levenshtein:v1.0.1:texttheater_golang_levenshtein/provider/vendor/github.com/texttheater/golang-levenshtein \
		uber-go:atomic:v1.11.0:uber_go_atomic/provider/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.11.0:uber_go_multierr/provider/vendor/go.uber.org/multierr \
		uber:jaeger-client-go:v2.30.0:uber_jaeger_client_go/provider/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v2.4.1:uber_jaeger_lib/provider/vendor/github.com/uber/jaeger-lib \
		xanzy:ssh-agent:v0.3.3:xanzy_ssh_agent/provider/vendor/github.com/xanzy/ssh-agent \
		xo:terminfo:abceb7e1c41e:xo_terminfo/provider/vendor/github.com/xo/terminfo \
		zclconf:go-cty:v1.16.2:zclconf_go_cty/provider/vendor/github.com/zclconf/go-cty

GO_BUILDFLAGS=	-buildvcs=false \
		-ldflags "-X github.com/pulumi/pulumi-command/provider/pkg/version.Version=${DISTVERSION}"

PLIST_FILES=	bin/pulumi-resource-command

post-extract:
	@${CP} ${FILESDIR}/modules.txt ${WRKSRC}/provider/vendor/
	@${RM} -r ${WRKSRC}/provider/vendor/github.com/charmbracelet/x/ansi
	@${RLN} ${WRKSRC_charmbracelet_x_ansi}/ansi \
		${WRKSRC}/provider/vendor/github.com/charmbracelet/x/ansi
	@${RM} -r ${WRKSRC}/provider/vendor/github.com/charmbracelet/x/cellbuf
	@${RLN} ${WRKSRC_charmbracelet_x_cellbuf}/cellbuf \
		${WRKSRC}/provider/vendor/github.com/charmbracelet/x/cellbuf
	@${MKDIR} ${WRKSRC}/provider/vendor/github.com/pulumi/pulumi/sdk
	@${RLN} ${WRKSRC_pulumi_pulumi_sdk}/sdk \
		${WRKSRC}/provider/vendor/github.com/pulumi/pulumi/sdk/v3
	@${MKDIR} ${WRKSRC}/provider/vendor/github.com/pulumi/pulumi/pkg
	@${RLN} ${WRKSRC_pulumi_pulumi_pkg}/pkg \
		${WRKSRC}/provider/vendor/github.com/pulumi/pulumi/pkg/v3

do-build:
	@${ECHO_MSG} "===> Building pulumi-resource-command"
	cd ${WRKSRC}/provider && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} \
		GOMAXPROCS=${MAKE_JOBS_NUMBER} GOPROXY=off \
		${GO_CMD} build ${GO_BUILDFLAGS} \
		-o ${WRKSRC}/bin/pulumi-resource-command \
		./cmd/pulumi-resource-command

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pulumi-resource-command \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
