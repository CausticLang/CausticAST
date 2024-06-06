compile_proto() {
    name=`basename -s ".part.proto" "$1"`
    pkgname=`$2 && echo "cst" || echo "cst.$name"`
    echo "$name[$pkgname]: $1"
    (
        echo -e "syntax = 'proto2';\n"
        echo -e "option optimize_for = LITE_RUNTIME;\n"
        $2 && echo -e "package cst;\n" || echo -e "package $pkgname;\n"
        cat "$1"
    ) > "./$name.proto"
    protoc --c_out . "./$name.proto"
}

export -f compile_proto

find -name '*.part.proto' -not -name 'nodes.part.proto' -exec bash -c 'compile_proto "$0" false' {} \;

compile_proto './nodes.part.proto' true

find -name '*.proto' -not -name '*.part.proto' -delete
