#include <gtest/gtest.h>
#include <codex/buffer/block.hpp>
#include <codex/buffer/block_factory.hpp>

TEST( block , create ) {
    codex::rc_ptr<codex::buffer::block<>> bptr = codex::buffer::block_factory<>::create( 32 );
    ASSERT_NE( bptr.get() , nullptr );
    ASSERT_EQ( bptr->size() , 32 );
    memset( bptr->data() , 0x00 , 32 );
    bptr.release();
    ASSERT_EQ( bptr.get() , nullptr );
}