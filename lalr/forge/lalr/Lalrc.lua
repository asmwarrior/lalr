
local Lalrc = forge:TargetPrototype( 'Lalrc' );

function Lalrc.create( forge, identifier )
    local target = forge:File( identifier, Lalrc );
    local lalrc = forge:interpolate( forge.settings.lalr.lalrc );
    target:add_implicit_dependency( forge:Target(lalrc) );
    target:set_cleanable( false );
    return target;
end

function Lalrc.build( forge, target )
    local lalrc = target:implicit_dependency();
    target:clear_implicit_dependencies();
    target:add_implicit_dependency( lalrc );

    local filename = target:filename();
    printf( forge:leaf(filename) );
    forge:system( lalrc, ('lalrc -o "%s" "%s"'):format(filename, target:dependency()) );
end
