#pragma once

template <typename DerivedT>
class LibraryInitialiser {
public:
    LibraryInitialiser();
    ~LibraryInitialiser();

    LibraryInitialiser(const LibraryInitialiser& other) = delete;
    auto operator==(const LibraryInitialiser& other) -> LibraryInitialiser& = delete;
    LibraryInitialiser(LibraryInitialiser&& other) noexcept = delete;
    auto operator==(LibraryInitialiser&& other) noexcept -> LibraryInitialiser& = delete;

private:
    static int count;
};

template <typename DerivedT>
int LibraryInitialiser<DerivedT>::count = 0;

template <typename DerivedT>
LibraryInitialiser<DerivedT>::LibraryInitialiser() {
    if (count == 0) {
        DerivedT::init();
    }

    ++count;
}

template <typename DerivedT>
LibraryInitialiser<DerivedT>::~LibraryInitialiser() {
    --count;

    if (count == 0) {
        DerivedT::deinit();
    }
}