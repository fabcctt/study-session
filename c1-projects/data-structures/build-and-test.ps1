param(
    [string]$Compiler = 'gcc',
    [ValidateSet('all', 'arrays', 'linked-list', 'stack', 'queue', 'binary-search',
        'max-heap', 'heap-sort', 'trie', 'union-find', 'graphs')]
    [string]$Project = 'all'
)

$ErrorActionPreference = 'Stop'
$projects = [ordered]@{
    'arrays' = @('dynamic_array.c')
    'linked-list' = @('list.c')
    'stack' = @('stack.c')
    'queue' = @('queue.c')
    'binary-search' = @('binary_search.c')
    'max-heap' = @('max_heap.c')
    'heap-sort' = @('heap_sort.c')
    'trie' = @('trie.c')
    'union-find' = @('union_find.c')
    'graphs' = @('graph.c', 'queue.c', 'stack.c')
}
$flags = @('-std=c11', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-g')
$passed = 0

Get-Command $Compiler -ErrorAction Stop | Out-Null
foreach ($name in $projects.Keys) {
    if ($Project -ne 'all' -and $Project -ne $name) { continue }
    Push-Location (Join-Path $PSScriptRoot $name)
    try {
        New-Item -ItemType Directory -Force -Path build | Out-Null
        $sources = $projects[$name]
        Write-Output "Building $name..."
        & $Compiler @flags @sources main.c -o build/demo.exe
        if ($LASTEXITCODE -ne 0) { throw "Demo compilation failed: $name" }
        & $Compiler @flags @sources tests.c -o build/tests.exe
        if ($LASTEXITCODE -ne 0) { throw "Test compilation failed: $name" }
        & .\build\demo.exe
        if ($LASTEXITCODE -ne 0) { throw "Demo failed: $name" }
        & .\build\tests.exe
        if ($LASTEXITCODE -ne 0) { throw "Tests failed: $name" }
        ++$passed
    }
    finally {
        Pop-Location
    }
}
Write-Output "Passed: $passed project(s)."
