# TODO — Genome Aligner in C++

---

## M0 — Project Bootstrap
- [x] Setup repo structure (`src/`, `include/`, `tests/`, `data/`).
- [x] Add CMake build system.
- [x] Implement minimal CLI
- [ ] FASTA/FASTQ parser stubs.
- [ ] Output stub SAM file with minimal header.

---

## M1 — Exact Mapper
- [ ] Build reference k-mer index (rolling hash, k=21).
- [ ] Implement read k-mer lookup.
- [ ] Exact match verification.
- [ ] Output SAM with `CIGAR=<len>M`.
- [ ] Benchmark indexing speed/memory.

---

## M2 — Mismatch Tolerant
- [ ] Add Hamming-distance verification of candidates.
- [ ] Return best candidate with ≤ m mismatches.
- [ ] Crude MAPQ score (best1/best2 heuristic).
- [ ] Handle multimappers (secondary alignment flag 0x100).
- [ ] Unit tests for mismatch scoring.

---

## M3 — Gapped Extension
- [ ] Implement banded Smith–Waterman with affine gaps.
- [ ] Add traceback → CIGAR string.
- [ ] Add `NM` (edit distance) and `AS` (alignment score) tags.
- [ ] Tune band size for Illumina read lengths.

---

## M4 — Chaining
- [ ] Implement multi-seed strategy (sample every N bp).
- [ ] Greedy co-linear chaining of seeds.
- [ ] Upgrade to DP-based chaining.
- [ ] Filter repetitive/low-complexity seeds.

---

## M5 — Multithreading & Scaling
- [ ] Producer-consumer queue with thread pool.
- [ ] Benchmark linear scaling across cores.
- [ ] Stress test on 5 Mb bacterial genome.
- [ ] Profile memory usage.

---

## M6 — Paired-End Support
- [ ] Implement orientation + insert size checks.
- [ ] Add mate rescue logic.
- [ ] Update SAM with proper pair flags.

---

## Future Work
- [ ] Long-read support (minimizers + chaining).
- [ ] SIMD DP (striped SW, SSE/AVX).
- [ ] FM-index/BWT indexing.
- [ ] BAM output via htslib.
- [ ] Splice-aware alignment for RNA-seq.
