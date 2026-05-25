const pptxgen = require("pptxgenjs");

const pres = new pptxgen();
pres.layout = "LAYOUT_16x9";
pres.title = "5G Packet Size Reduction Using ROHC — Review 3";

// ── Palette ──────────────────────────────────────────────────────────────────
const BG      = "0B1437";
const CARD    = "132157";
const ACCENT1 = "1DA8E0";  // cyan
const ACCENT2 = "F59E0B";  // amber
const ACCENT3 = "10B981";  // green
const WHITE   = "FFFFFF";
const MUTED   = "94A3B8";
const ORANGE  = "F97316";
const RED     = "EF4444";
const PURPLE  = "7C3AED";
const DARK    = "0D1B3E";

const makeShadow = () => ({
  type: "outer", blur: 8, offset: 3, angle: 135, color: "000000", opacity: 0.20,
});

function card(slide, x, y, w, h, color = CARD) {
  slide.addShape(pres.shapes.ROUNDED_RECTANGLE, {
    x, y, w, h,
    fill: { color },
    line: { color: "1E3A6A", width: 0.5 },
    shadow: makeShadow(),
    rectRadius: 0.08,
  });
}

function statBox(slide, x, y, w, big, small, bigColor = ACCENT3) {
  card(slide, x, y, w, 1.1);
  const sz = big.length > 8 ? 22 : big.length > 6 ? 28 : 36;
  slide.addText(big, {
    x, y: y + 0.05, w, h: 0.65, fontSize: sz, bold: true, color: bigColor,
    align: "center", valign: "middle", fontFace: "Calibri", shrinkText: true,
  });
  slide.addText(small, {
    x, y: y + 0.7, w, h: 0.35, fontSize: 10, color: MUTED,
    align: "center", fontFace: "Calibri",
  });
}

// ── Arrow helper ─────────────────────────────────────────────────────────────
function arrow(slide, x1, y, x2, color = ACCENT1) {
  slide.addShape(pres.shapes.LINE, {
    x: x1, y, w: x2 - x1, h: 0,
    line: { color, width: 2 },
  });
  // arrowhead triangle
  const aw = 0.12, ah = 0.12;
  slide.addShape(pres.shapes.RECTANGLE, {
    x: x2 - aw, y: y - ah / 2, w: aw, h: ah,
    fill: { color }, line: { color, width: 0 },
  });
}

function downArrow(slide, x, y1, y2, color = ACCENT1) {
  slide.addShape(pres.shapes.LINE, {
    x, y: y1, w: 0, h: y2 - y1,
    line: { color, width: 2 },
  });
}

// ─────────────────────────────────────────────────────────────────────────────
// SLIDE 1 – TITLE
// ─────────────────────────────────────────────────────────────────────────────
{
  const s = pres.addSlide();
  s.background = { color: BG };

  s.addShape(pres.shapes.RECTANGLE, { x: 0, y: 0, w: 10, h: 0.06, fill: { color: ACCENT1 } });

  s.addText("KLE Technological University  ·  Dept. of Electronics & Communication Engineering", {
    x: 0.5, y: 0.18, w: 9, h: 0.3, fontSize: 11, color: MUTED, align: "center", fontFace: "Calibri",
  });

  s.addText("5G Packet Size Reduction\nUsing ROHC in the PDCP Layer", {
    x: 0.8, y: 0.65, w: 8.4, h: 1.65, fontSize: 38, bold: true, color: WHITE,
    align: "center", valign: "middle", fontFace: "Calibri",
  });

  s.addShape(pres.shapes.ROUNDED_RECTANGLE, {
    x: 3.5, y: 2.4, w: 3.0, h: 0.55, fill: { color: ACCENT1 }, rectRadius: 0.1,
  });
  s.addText("Minor Project — Review 3", {
    x: 3.5, y: 2.4, w: 3.0, h: 0.55, fontSize: 16, bold: true, color: WHITE,
    align: "center", valign: "middle", fontFace: "Calibri",
  });

  const team = [
    ["Srikrishna Hireholi", "01FE23BEC224"],
    ["Swaroop Swamy",       "01FE23BEC222"],
    ["Mahantesh Imagoudar", "01FE23BEC166"],
    ["Karthik Terdal",      "01FE23BEC174"],
  ];
  team.forEach(([name, usn], i) => {
    const col = i < 2 ? 0 : 1;
    const row = i % 2;
    const cx = 1.4 + col * 4.9;
    const cy = 3.15 + row * 0.56;
    card(s, cx, cy, 3.9, 0.48);
    s.addText(`${name}  ·  ${usn}`, {
      x: cx + 0.1, y: cy + 0.04, w: 3.7, h: 0.4,
      fontSize: 12, color: WHITE, fontFace: "Calibri", align: "center",
    });
  });

  s.addText("Guide: Rajeshwari B, HOD (E&C)  ·  Academic Year 2025–26, Even Semester", {
    x: 0.5, y: 5.18, w: 9, h: 0.28, fontSize: 10, color: MUTED, align: "center", fontFace: "Calibri",
  });

  s.addShape(pres.shapes.RECTANGLE, { x: 0, y: 5.55, w: 10, h: 0.075, fill: { color: ACCENT2 } });
}

// ─────────────────────────────────────────────────────────────────────────────
// SLIDE 2 – AGENDA
// ─────────────────────────────────────────────────────────────────────────────
{
  const s = pres.addSlide();
  s.background = { color: BG };

  s.addText("Agenda", {
    x: 0.5, y: 0.18, w: 9, h: 0.5, fontSize: 32, bold: true, color: WHITE, fontFace: "Calibri",
  });

  const items = [
    ["01", "What is the Problem?",          "Header overhead wastes spectrum & battery at 5G scale"],
    ["02", "How ROHC Solves It",            "3 simple states explained with real analogies"],
    ["03", "System Architecture",           "Full pipeline block diagram — how it all connects"],
    ["04", "Enhancement 1: QASROHC",        "Adaptive compression speed per 5G traffic type"],
    ["05", "Enhancement 2: PAFPT",          "Split big packets — start decoding early"],
    ["06", "Results at a Glance",           "Compression ratios, MB saved, latency gains"],
    ["07", "Summary & Next Steps",          "What's done, what's coming — final submission plan"],
  ];

  items.forEach(([num, title, sub], i) => {
    const y = 0.9 + i * 0.66;
    s.addShape(pres.shapes.OVAL, { x: 0.4, y: y + 0.06, w: 0.44, h: 0.44, fill: { color: ACCENT1 } });
    s.addText(num, {
      x: 0.4, y: y + 0.06, w: 0.44, h: 0.44, fontSize: 13, bold: true, color: WHITE,
      align: "center", valign: "middle", fontFace: "Calibri",
    });
    s.addText(title, {
      x: 1.05, y: y, w: 4.0, h: 0.38, fontSize: 15, bold: true, color: WHITE,
      fontFace: "Calibri", margin: 0,
    });
    s.addText(sub, {
      x: 1.05, y: y + 0.36, w: 8.6, h: 0.26, fontSize: 11, color: MUTED,
      fontFace: "Calibri", margin: 0,
    });
  });
}

// ─────────────────────────────────────────────────────────────────────────────
// SLIDE 3 – SIMPLE PROBLEM EXPLANATION
// ─────────────────────────────────────────────────────────────────────────────
{
  const s = pres.addSlide();
  s.background = { color: BG };

  s.addText("The Problem — In Simple Terms", {
    x: 0.5, y: 0.15, w: 9, h: 0.48, fontSize: 28, bold: true, color: WHITE, fontFace: "Calibri",
  });

  // Packet anatomy diagram
  card(s, 0.4, 0.75, 9.2, 1.35, DARK);
  s.addText("Every packet sent on 5G looks like this:", {
    x: 0.6, y: 0.82, w: 4.0, h: 0.3, fontSize: 12, color: MUTED, fontFace: "Calibri",
  });

  // Header block
  s.addShape(pres.shapes.RECTANGLE, { x: 0.7, y: 1.15, w: 2.1, h: 0.72, fill: { color: RED } });
  s.addText("HEADER\n40 bytes = 0.039 MB", {
    x: 0.7, y: 1.15, w: 2.1, h: 0.72, fontSize: 12, bold: true, color: WHITE,
    align: "center", valign: "middle", fontFace: "Calibri",
  });
  // Payload block
  s.addShape(pres.shapes.RECTANGLE, { x: 2.8, y: 1.15, w: 6.6, h: 0.72, fill: { color: ACCENT3 } });
  s.addText("PAYLOAD (Actual Data)", {
    x: 2.8, y: 1.15, w: 6.6, h: 0.72, fontSize: 14, bold: true, color: WHITE,
    align: "center", valign: "middle", fontFace: "Calibri",
  });

  // Two column comparisons
  card(s, 0.4, 2.25, 4.4, 1.65, "1C1020");
  s.addText("IoT Sensor", { x: 0.6, y: 2.3, w: 4.0, h: 0.34, fontSize: 15, bold: true, color: ORANGE, fontFace: "Calibri" });
  // mini bar
  s.addShape(pres.shapes.RECTANGLE, { x: 0.6, y: 2.68, w: 2.0, h: 0.45, fill: { color: RED } });
  s.addText("Header 40 B", { x: 0.6, y: 2.68, w: 2.0, h: 0.45, fontSize: 9, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });
  s.addShape(pres.shapes.RECTANGLE, { x: 2.6, y: 2.68, w: 1.05, h: 0.45, fill: { color: ACCENT3 } });
  s.addText("Payload 20 B", { x: 2.6, y: 2.68, w: 1.05, h: 0.45, fontSize: 9, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });
  s.addText("Header = 67% of every packet! (wasted spectrum)", {
    x: 0.6, y: 3.18, w: 4.0, h: 0.6, fontSize: 11, color: ORANGE, fontFace: "Calibri", bold: true,
  });

  card(s, 5.2, 2.25, 4.4, 1.65, "0A1E2E");
  s.addText("VoIP Call", { x: 5.4, y: 2.3, w: 4.0, h: 0.34, fontSize: 15, bold: true, color: ACCENT2, fontFace: "Calibri" });
  s.addShape(pres.shapes.RECTANGLE, { x: 5.4, y: 2.68, w: 1.1, h: 0.45, fill: { color: RED } });
  s.addText("Header 40 B", { x: 5.4, y: 2.68, w: 1.1, h: 0.45, fontSize: 9, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });
  s.addShape(pres.shapes.RECTANGLE, { x: 6.5, y: 2.68, w: 2.8, h: 0.45, fill: { color: ACCENT3 } });
  s.addText("Payload 160 B", { x: 6.5, y: 2.68, w: 2.8, h: 0.45, fontSize: 9, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });
  s.addText("Header = 20% of every VoIP packet (millions of calls!)", {
    x: 5.4, y: 3.18, w: 4.0, h: 0.6, fontSize: 11, color: ACCENT2, fontFace: "Calibri", bold: true,
  });

  // Scale banner
  card(s, 0.4, 4.05, 9.2, 0.55, "1a1040");
  s.addText("At 1 million IoT devices sending 1 packet/sec  →  ~37 MB/s of PURE WASTED HEADER DATA on the air", {
    x: 0.6, y: 4.12, w: 8.8, h: 0.4, fontSize: 12, bold: true, color: ACCENT2, align: "center", fontFace: "Calibri",
  });

  // After ROHC
  card(s, 0.4, 4.72, 9.2, 0.62, "061A0D");
  s.addText("✔  ROHC compresses that 40-byte (0.039 MB) header down to just 1–3 bytes (0.001–0.003 MB) in steady state  →  saves ~37 bytes per packet", {
    x: 0.6, y: 4.79, w: 8.8, h: 0.48, fontSize: 11, color: ACCENT3, align: "center", fontFace: "Calibri",
  });
}

// ─────────────────────────────────────────────────────────────────────────────
// SLIDE 4 – ROHC 3 STATES (simple analogy)
// ─────────────────────────────────────────────────────────────────────────────
{
  const s = pres.addSlide();
  s.background = { color: BG };

  s.addText("How ROHC Works — 3 Simple States", {
    x: 0.5, y: 0.15, w: 9, h: 0.48, fontSize: 28, bold: true, color: WHITE, fontFace: "Calibri",
  });

  // Analogy banner
  card(s, 0.4, 0.72, 9.2, 0.5, "0A1530");
  s.addText("Think of it like two friends talking repeatedly — they stop repeating everything once they know each other", {
    x: 0.6, y: 0.78, w: 8.8, h: 0.38, fontSize: 12, color: ACCENT2, italic: true, align: "center", fontFace: "Calibri",
  });

  // State 1
  card(s, 0.3, 1.32, 2.85, 2.95, "300A0A");
  s.addShape(pres.shapes.OVAL, { x: 1.25, y: 1.42, w: 0.9, h: 0.9, fill: { color: RED } });
  s.addText("IR", { x: 1.25, y: 1.42, w: 0.9, h: 0.9, fontSize: 20, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });
  s.addText("Init & Refresh", { x: 0.35, y: 2.38, w: 2.75, h: 0.3, fontSize: 12, bold: true, color: RED, align: "center", fontFace: "Calibri" });
  s.addText("40 bytes\n= 0.039 MB", { x: 0.35, y: 2.66, w: 2.75, h: 0.38, fontSize: 14, bold: true, color: ACCENT2, align: "center", fontFace: "Calibri" });
  s.addText("Full header sent.\nReceiver learns everything.\nLike: \"Hi, I'm Srikrishna from Hubballi, my number is XYZ\"", {
    x: 0.4, y: 3.06, w: 2.7, h: 1.1, fontSize: 10, color: MUTED, align: "center", fontFace: "Calibri",
  });

  // Arrow IR → FO
  s.addText("→", { x: 3.17, y: 2.5, w: 0.5, h: 0.4, fontSize: 22, bold: true, color: ACCENT1, align: "center", fontFace: "Calibri" });
  s.addText("context\nestab.", { x: 3.12, y: 2.88, w: 0.62, h: 0.42, fontSize: 8, color: MUTED, align: "center", fontFace: "Calibri" });

  // State 2
  card(s, 3.73, 1.32, 2.85, 2.95, "2A1E00");
  s.addShape(pres.shapes.OVAL, { x: 4.67, y: 1.42, w: 0.9, h: 0.9, fill: { color: ACCENT2 } });
  s.addText("FO", { x: 4.67, y: 1.42, w: 0.9, h: 0.9, fontSize: 20, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });
  s.addText("First Order", { x: 3.78, y: 2.38, w: 2.75, h: 0.3, fontSize: 12, bold: true, color: ACCENT2, align: "center", fontFace: "Calibri" });
  s.addText("4–12 bytes\n= 0.004–0.012 MB", { x: 3.78, y: 2.66, w: 2.75, h: 0.38, fontSize: 13, bold: true, color: ACCENT2, align: "center", fontFace: "Calibri" });
  s.addText("Only changes sent.\nSeq +1, Timestamp +160.\nLike: \"Bro, same person, new message\"", {
    x: 3.8, y: 3.06, w: 2.7, h: 1.1, fontSize: 10, color: MUTED, align: "center", fontFace: "Calibri",
  });

  // Arrow FO → SO
  s.addText("→", { x: 6.61, y: 2.5, w: 0.5, h: 0.4, fontSize: 22, bold: true, color: ACCENT1, align: "center", fontFace: "Calibri" });
  s.addText("confidence\nbuilt", { x: 6.56, y: 2.88, w: 0.62, h: 0.42, fontSize: 8, color: MUTED, align: "center", fontFace: "Calibri" });

  // State 3
  card(s, 7.15, 1.32, 2.52, 2.95, "052E1A");
  s.addShape(pres.shapes.OVAL, { x: 8.07, y: 1.42, w: 0.9, h: 0.9, fill: { color: ACCENT3 } });
  s.addText("SO", { x: 8.07, y: 1.42, w: 0.9, h: 0.9, fontSize: 20, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });
  s.addText("Second Order", { x: 7.2, y: 2.38, w: 2.42, h: 0.3, fontSize: 12, bold: true, color: ACCENT3, align: "center", fontFace: "Calibri" });
  s.addText("1–3 bytes\n= 0.001 MB", { x: 7.2, y: 2.66, w: 2.42, h: 0.38, fontSize: 14, bold: true, color: ACCENT3, align: "center", fontFace: "Calibri" });
  s.addText("Receiver predicts everything.\nSender sends only tiny ID.\nLike: \"Packet 25\" and receiver knows all.", {
    x: 7.22, y: 3.06, w: 2.4, h: 1.1, fontSize: 10, color: MUTED, align: "center", fontFace: "Calibri",
  });

  // Loss arrow
  card(s, 0.3, 4.42, 9.4, 0.52, "1C0A0A");
  s.addText("⚠  If a packet is lost → receiver context becomes wrong → ROHC resets back to IR and resends full header to fix it", {
    x: 0.5, y: 4.49, w: 9.0, h: 0.38, fontSize: 11, color: ORANGE, align: "center", fontFace: "Calibri",
  });

  // Why not jump directly
  card(s, 0.3, 5.04, 9.4, 0.42, DARK);
  s.addText("💡  Why not jump to SO immediately? Because receiver needs to first LEARN the pattern — rushing causes wrong reconstruction!", {
    x: 0.5, y: 5.1, w: 9.0, h: 0.3, fontSize: 11, color: ACCENT2, italic: true, align: "center", fontFace: "Calibri",
  });
}

// ─────────────────────────────────────────────────────────────────────────────
// SLIDE 5 – FULL SYSTEM ARCHITECTURE BLOCK DIAGRAM
// ─────────────────────────────────────────────────────────────────────────────
{
  const s = pres.addSlide();
  s.background = { color: BG };

  s.addText("System Architecture — Complete Pipeline", {
    x: 0.5, y: 0.12, w: 9, h: 0.45, fontSize: 26, bold: true, color: WHITE, fontFace: "Calibri",
  });
  s.addText("How data flows from packet creation → compression → channel → decompression → analysis", {
    x: 0.5, y: 0.55, w: 9, h: 0.25, fontSize: 11, color: MUTED, italic: true, fontFace: "Calibri",
  });

  // ── Top row: main pipeline blocks ───────────────────────────────────────────
  const blocks = [
    { label: "Packet\nGenerator", sub: "Creates synthetic\nIP/UDP/RTP packets\n(VoIP 160 B / IoT 20 B)", color: "1E4D8C", x: 0.15 },
    { label: "PAFPT\nModule", sub: "Splits large SDUs\ninto Priority Segment\n& Bulk Segment", color: PURPLE.replace("#",""), x: 2.05 },
    { label: "ROHC\nCompressor\n(PDCP Tx)", sub: "IR → FO → SO\nstate machine\n+ QASROHC logic", color: "165C3A", x: 3.95 },
    { label: "5G Channel\nSimulator", sub: "Adds packet loss\n(0%, 1%, 5%)\n& latency", color: "5B2B00", x: 5.85 },
    { label: "ROHC\nDecompressor\n(PDCP Rx)", sub: "Rebuilds full\n40 B header\nfrom context", color: "165C3A", x: 7.75 },
  ];

  const BW = 1.72, BH = 1.42, BY = 0.9;
  blocks.forEach(({ label, sub, color, x }, i) => {
    s.addShape(pres.shapes.ROUNDED_RECTANGLE, {
      x, y: BY, w: BW, h: BH,
      fill: { color }, shadow: makeShadow(), rectRadius: 0.08,
    });
    s.addText(label, {
      x, y: BY + 0.05, w: BW, h: 0.55, fontSize: 11, bold: true, color: WHITE,
      align: "center", valign: "middle", fontFace: "Calibri",
    });
    s.addText(sub, {
      x: x + 0.07, y: BY + 0.62, w: BW - 0.14, h: 0.72, fontSize: 9, color: "B0D8FF",
      align: "center", fontFace: "Calibri",
    });
    // forward arrows between blocks
    if (i < blocks.length - 1) {
      const ax = x + BW;
      const ay = BY + BH / 2;
      s.addShape(pres.shapes.LINE, { x: ax, y: ay, w: 0.33, h: 0, line: { color: ACCENT1, width: 2 } });
      s.addText("▶", { x: ax + 0.18, y: ay - 0.16, w: 0.24, h: 0.24, fontSize: 10, color: ACCENT1, align: "center", fontFace: "Calibri" });
    }
  });

  // ── Feedback NACK arrow (bottom, right to left) ──────────────────────────
  const nackY = BY + BH + 0.18;
  s.addShape(pres.shapes.LINE, { x: 0.9, y: nackY, w: 8.5, h: 0, line: { color: ORANGE, width: 1.5, dashType: "dash" } });
  s.addText("◀  NACK feedback: loss detected → reset to IR state", {
    x: 1.0, y: nackY + 0.04, w: 7.5, h: 0.26, fontSize: 10, color: ORANGE, italic: true, fontFace: "Calibri",
  });

  // ── Second row: output block ──────────────────────────────────────────────
  const perfY = nackY + 0.46;
  s.addShape(pres.shapes.ROUNDED_RECTANGLE, {
    x: 3.0, y: perfY, w: 4.0, h: 1.0,
    fill: { color: "7A1C1C" }, shadow: makeShadow(), rectRadius: 0.08,
  });
  s.addText("Metrics & Visualisation", {
    x: 3.0, y: perfY + 0.06, w: 4.0, h: 0.36, fontSize: 13, bold: true, color: WHITE,
    align: "center", fontFace: "Calibri",
  });
  s.addText("Compression ratio  ·  MB saved per packet  ·  Latency (µs)  ·  Throughput (MB/s)", {
    x: 3.1, y: perfY + 0.44, w: 3.8, h: 0.44, fontSize: 10, color: MUTED, align: "center", fontFace: "Calibri",
  });

  // lines from decompressor block down to metrics
  s.addShape(pres.shapes.LINE, {
    x: 8.61, y: BY + BH, w: 0, h: perfY - (BY + BH),
    line: { color: MUTED, width: 1, dashType: "sysDot" },
  });
  s.addShape(pres.shapes.LINE, {
    x: 5.0, y: perfY, w: 3.61, h: 0,
    line: { color: MUTED, width: 1, dashType: "sysDot" },
  });

  // ── QASROHC annotation ───────────────────────────────────────────────────
  s.addShape(pres.shapes.ROUNDED_RECTANGLE, {
    x: 0.15, y: perfY, w: 2.6, h: 0.88, fill: { color: "061A0D" }, rectRadius: 0.07,
    line: { color: ACCENT3, width: 1 },
  });
  s.addText("QASROHC", { x: 0.15, y: perfY + 0.06, w: 2.6, h: 0.3, fontSize: 12, bold: true, color: ACCENT3, align: "center", fontFace: "Calibri" });
  s.addText("Adjusts k₁ & k₂\nper QoS flow class\n(URLLC / eMBB / mMTC)", { x: 0.2, y: perfY + 0.36, w: 2.5, h: 0.46, fontSize: 9, color: MUTED, align: "center", fontFace: "Calibri" });

  // dotted line QASROHC → compressor
  s.addShape(pres.shapes.LINE, {
    x: 2.75, y: perfY + 0.44, w: 1.2, h: 0,
    line: { color: ACCENT3, width: 1, dashType: "dash" },
  });
  s.addText("▶", { x: 3.8, y: perfY + 0.3, w: 0.22, h: 0.24, fontSize: 9, color: ACCENT3, align: "center", fontFace: "Calibri" });

  // legend
  s.addText("━  Data flow     ╌  NACK / control    ┄  Influence", {
    x: 0.3, y: 5.45, w: 9.4, h: 0.25, fontSize: 10, color: MUTED, align: "center", italic: true, fontFace: "Calibri",
  });
}

// ─────────────────────────────────────────────────────────────────────────────
// SLIDE 6 – ROHC STATE MACHINE FLOW DIAGRAM
// ─────────────────────────────────────────────────────────────────────────────
{
  const s = pres.addSlide();
  s.background = { color: BG };

  s.addText("ROHC State Machine — Detailed Flow", {
    x: 0.5, y: 0.12, w: 9, h: 0.45, fontSize: 26, bold: true, color: WHITE, fontFace: "Calibri",
  });

  // State boxes
  const states = [
    { name: "IR State", size: "40 B / 0.039 MB", color: RED,    x: 0.5,  analogy: "\"Hi, I'm Srikrishna from Hubballi, my phone is XYZ\"" },
    { name: "FO State", size: "4–12 B / 0.004–0.012 MB", color: ACCENT2, x: 3.75, analogy: "\"Bro, same person, update #25\"" },
    { name: "SO State", size: "1–3 B / 0.001–0.003 MB", color: ACCENT3, x: 7.0,  analogy: "\"Packet 25\" — receiver fills in the rest!" },
  ];

  const SBW = 2.7, SBH = 1.55, SBY = 0.72;
  states.forEach(({ name, size, color, x, analogy }) => {
    s.addShape(pres.shapes.ROUNDED_RECTANGLE, { x, y: SBY, w: SBW, h: SBH, fill: { color }, shadow: makeShadow(), rectRadius: 0.1 });
    s.addText(name, { x, y: SBY + 0.1, w: SBW, h: 0.38, fontSize: 18, bold: true, color: WHITE, align: "center", fontFace: "Calibri" });
    s.addText(size, { x, y: SBY + 0.52, w: SBW, h: 0.38, fontSize: 15, bold: true, color: WHITE, align: "center", fontFace: "Calibri" });
    s.addText(analogy, { x: x + 0.1, y: SBY + 0.95, w: SBW - 0.2, h: 0.52, fontSize: 9.5, color: "E0F2FE", align: "center", fontFace: "Calibri", italic: true });
  });

  // Arrows IR→FO, FO→SO
  const arrowY = SBY + SBH / 2;
  [[3.2, "context\nestablished"], [6.45, "confidence\nbuilt"]]
    .forEach(([ax, lbl]) => {
      s.addShape(pres.shapes.LINE, { x: ax, y: arrowY, w: 0.55, h: 0, line: { color: ACCENT1, width: 2.5 } });
      s.addText("▶", { x: ax + 0.36, y: arrowY - 0.2, w: 0.24, h: 0.24, fontSize: 11, color: ACCENT1, align: "center", fontFace: "Calibri" });
      s.addText(lbl, { x: ax - 0.05, y: arrowY + 0.12, w: 0.65, h: 0.36, fontSize: 8, color: ACCENT1, align: "center", fontFace: "Calibri" });
    });

  // Loss reset arrow (curved representation using line)
  s.addText("⤶  Packet Loss Detected", {
    x: 0.4, y: SBY + SBH + 0.22, w: 3.5, h: 0.3, fontSize: 12, bold: true, color: ORANGE, fontFace: "Calibri",
  });
  s.addShape(pres.shapes.LINE, {
    x: 0.5, y: SBY + SBH + 0.18, w: 9.0, h: 0, line: { color: ORANGE, width: 1.5, dashType: "dash" },
  });
  s.addText("→ NACK sent back → Compressor resets to IR → Resends full 40 B header → Context rebuilt within 2 packets", {
    x: 3.8, y: SBY + SBH + 0.22, w: 5.7, h: 0.3, fontSize: 10, color: ORANGE, fontFace: "Calibri",
  });

  // Step by step packet trace
  card(s, 0.4, 2.88, 9.2, 2.52, DARK);
  s.addText("Step-by-Step: What happens packet by packet", {
    x: 0.6, y: 2.95, w: 8.8, h: 0.32, fontSize: 13, bold: true, color: WHITE, fontFace: "Calibri",
  });

  const steps = [
    { n: "Pkt 1", state: "IR", sent: "Full 40 B header", why: "Receiver knows nothing yet — must teach it everything", col: RED },
    { n: "Pkt 2", state: "FO", sent: "Only Seq+1, TS+160 (~8 B)", why: "Receiver now knows IPs, ports etc. — only send what changed", col: ACCENT2 },
    { n: "Pkt 3", state: "FO", sent: "Same delta encoding (~8 B)", why: "Building confidence that receiver understands the pattern", col: ACCENT2 },
    { n: "Pkt 4+", state: "SO ✔", sent: "Tiny 1–3 byte identifier", why: "Receiver predicts everything — maximum compression achieved!", col: ACCENT3 },
  ];

  steps.forEach(({ n, state, sent, why, col }, i) => {
    const row = i < 2 ? 0 : 1;
    const col2 = i % 2;
    const cx = 0.55 + col2 * 4.65;
    const cy = 3.35 + row * 0.95;

    s.addShape(pres.shapes.ROUNDED_RECTANGLE, { x: cx, y: cy, w: 4.35, h: 0.82, fill: { color: "0D1B3E" }, rectRadius: 0.06 });
    s.addShape(pres.shapes.OVAL, { x: cx + 0.08, y: cy + 0.16, w: 0.55, h: 0.5, fill: { color: col } });
    s.addText(n, { x: cx + 0.08, y: cy + 0.16, w: 0.55, h: 0.5, fontSize: 9, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });
    s.addText(`[${state}]  ${sent}`, { x: cx + 0.7, y: cy + 0.05, w: 3.55, h: 0.3, fontSize: 11, bold: true, color: WHITE, fontFace: "Calibri" });
    s.addText(why, { x: cx + 0.7, y: cy + 0.4, w: 3.55, h: 0.36, fontSize: 9, color: MUTED, fontFace: "Calibri" });
  });
}

// ─────────────────────────────────────────────────────────────────────────────
// SLIDE 7 – QASROHC FLOW DIAGRAM (simple)
// ─────────────────────────────────────────────────────────────────────────────
{
  const s = pres.addSlide();
  s.background = { color: BG };

  s.addText("Enhancement 1: QASROHC — Adaptive Speed", {
    x: 0.5, y: 0.12, w: 9, h: 0.45, fontSize: 26, bold: true, color: WHITE, fontFace: "Calibri",
  });

  // Analogy
  card(s, 0.4, 0.65, 9.2, 0.45, DARK);
  s.addText("Standard ROHC:  Everyone queues at the same speed.    QASROHC:  Emergency vehicles use the fast lane!", {
    x: 0.6, y: 0.72, w: 8.8, h: 0.32, fontSize: 12, color: ACCENT2, italic: true, align: "center", fontFace: "Calibri",
  });

  // Decision flow
  // Incoming packet box
  s.addShape(pres.shapes.ROUNDED_RECTANGLE, { x: 3.9, y: 1.22, w: 2.2, h: 0.55, fill: { color: "1E4D8C" }, rectRadius: 0.1 });
  s.addText("New Packet Arrives", { x: 3.9, y: 1.22, w: 2.2, h: 0.55, fontSize: 12, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });

  // Down arrow to decision
  s.addShape(pres.shapes.LINE, { x: 5.0, y: 1.77, w: 0, h: 0.35, line: { color: ACCENT1, width: 2 } });
  s.addText("▼", { x: 4.85, y: 2.04, w: 0.3, h: 0.25, fontSize: 13, color: ACCENT1, align: "center", fontFace: "Calibri" });

  // Diamond decision box (represented as rotated rectangle with text)
  s.addShape(pres.shapes.ROUNDED_RECTANGLE, { x: 3.5, y: 2.22, w: 3.0, h: 0.58, fill: { color: PURPLE }, rectRadius: 0.12 });
  s.addText("What QoS class is this?", { x: 3.5, y: 2.22, w: 3.0, h: 0.58, fontSize: 13, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });

  // Three branches
  const branches = [
    { label: "URLLC\nControl", sub: "k₁=1, k₂=1\nSO by packet 2", sub2: "Ultra-low latency\nEmergency packets", color: RED,    x: 0.4,  textX: 0.15 },
    { label: "eMBB\nVideo/Data", sub: "k₁=3, k₂=5\nSO by packet 9", sub2: "Long flows\nBuild reliability", color: ACCENT2, x: 3.75, textX: 3.5  },
    { label: "mMTC\nIoT Sensors", sub: "k₁=1, k₂=2\nSO by packet 3", sub2: "Short bursts\nMax efficiency", color: ACCENT3, x: 7.1,  textX: 6.85 },
  ];

  branches.forEach(({ label, sub, sub2, color, x, textX }) => {
    // Line down from decision diamond
    s.addShape(pres.shapes.LINE, { x: x + 1.25, y: 2.8, w: 0, h: 0.42, line: { color, width: 1.5, dashType: "sysDot" } });
    // Branch box
    s.addShape(pres.shapes.ROUNDED_RECTANGLE, { x, y: 3.22, w: 2.5, h: 0.72, fill: { color }, shadow: makeShadow(), rectRadius: 0.1 });
    s.addText(label, { x, y: 3.22, w: 2.5, h: 0.72, fontSize: 14, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });
    // Params box
    s.addShape(pres.shapes.ROUNDED_RECTANGLE, { x, y: 4.04, w: 2.5, h: 0.68, fill: { color: DARK }, rectRadius: 0.08 });
    s.addText(sub, { x, y: 4.04, w: 2.5, h: 0.68, fontSize: 13, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });
    // Why box
    s.addText(sub2, { x, y: 4.76, w: 2.5, h: 0.4, fontSize: 10, color: MUTED, align: "center", fontFace: "Calibri" });
  });

  // Connector lines from decision box to branch tops
  // URLLC — line left then down
  s.addShape(pres.shapes.LINE, { x: 3.5, y: 2.51, w: -1.85, h: 0, line: { color: RED, width: 1.5 } });
  // mMTC — line right then down  
  s.addShape(pres.shapes.LINE, { x: 6.5, y: 2.51, w: 1.85, h: 0, line: { color: ACCENT3, width: 1.5 } });

  // Result banner
  card(s, 0.4, 5.24, 9.2, 0.42, "061A0D");
  s.addText("Result: URLLC saves ~83% header overhead in first 10 packets  ·  mMTC saves ~70%  ·  All fully backward-compatible with standard ROHC", {
    x: 0.6, y: 5.3, w: 8.8, h: 0.3, fontSize: 11, color: ACCENT3, align: "center", fontFace: "Calibri",
  });
}

// ─────────────────────────────────────────────────────────────────────────────
// SLIDE 8 – PAFPT FLOW DIAGRAM
// ─────────────────────────────────────────────────────────────────────────────
{
  const s = pres.addSlide();
  s.background = { color: BG };

  s.addText("Enhancement 2: PAFPT — Split & Deliver Early", {
    x: 0.5, y: 0.12, w: 9, h: 0.45, fontSize: 26, bold: true, color: WHITE, fontFace: "Calibri",
  });

  // Analogy
  card(s, 0.4, 0.64, 9.2, 0.45, DARK);
  s.addText("Like receiving a book — you start reading Chapter 1 as soon as it arrives, without waiting for all 300 pages to print!", {
    x: 0.6, y: 0.71, w: 8.8, h: 0.32, fontSize: 12, color: ACCENT2, italic: true, align: "center", fontFace: "Calibri",
  });

  // ── Before PAFPT ────────────────────────────────────────────────────────────
  card(s, 0.3, 1.18, 4.2, 3.08, "1C0A0A");
  s.addText("❌  Without PAFPT", { x: 0.5, y: 1.24, w: 3.8, h: 0.34, fontSize: 14, bold: true, color: RED, fontFace: "Calibri", align: "center" });

  // Full SDU
  s.addShape(pres.shapes.RECTANGLE, { x: 0.5, y: 1.66, w: 3.8, h: 0.55, fill: { color: "1E4D8C" } });
  s.addText("Full Frame: 1400 B (0.0014 MB)", { x: 0.5, y: 1.66, w: 3.8, h: 0.55, fontSize: 12, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });

  s.addText("▼  Sent as ONE whole unit", { x: 0.5, y: 2.26, w: 3.8, h: 0.28, fontSize: 11, color: MUTED, align: "center", fontFace: "Calibri" });

  s.addShape(pres.shapes.ROUNDED_RECTANGLE, { x: 0.5, y: 2.6, w: 3.8, h: 0.58, fill: { color: "3B1111" }, rectRadius: 0.07 });
  s.addText("⏳ Receiver waits for ALL 1400 bytes", { x: 0.5, y: 2.6, w: 3.8, h: 0.58, fontSize: 11, bold: true, color: ORANGE, align: "center", valign: "middle", fontFace: "Calibri" });

  s.addText("▼  Only then can it start decoding", { x: 0.5, y: 3.23, w: 3.8, h: 0.28, fontSize: 11, color: MUTED, align: "center", fontFace: "Calibri" });

  s.addShape(pres.shapes.ROUNDED_RECTANGLE, { x: 0.5, y: 3.56, w: 3.8, h: 0.58, fill: { color: "3B1111" }, rectRadius: 0.07 });
  s.addText("Application processes frame\n(DELAYED — full wait time)", { x: 0.5, y: 3.56, w: 3.8, h: 0.58, fontSize: 11, color: RED, align: "center", valign: "middle", fontFace: "Calibri" });

  // ── After PAFPT ─────────────────────────────────────────────────────────────
  card(s, 5.5, 1.18, 4.2, 3.08, "061A0D");
  s.addText("✔  With PAFPT", { x: 5.7, y: 1.24, w: 3.8, h: 0.34, fontSize: 14, bold: true, color: ACCENT3, fontFace: "Calibri", align: "center" });

  // Priority segment
  s.addShape(pres.shapes.RECTANGLE, { x: 5.7, y: 1.64, w: 1.4, h: 0.55, fill: { color: ACCENT1 } });
  s.addText("Priority\nSeg. ~130 B", { x: 5.7, y: 1.64, w: 1.4, h: 0.55, fontSize: 9, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });
  // Bulk segment
  s.addShape(pres.shapes.RECTANGLE, { x: 7.1, y: 1.64, w: 2.35, h: 0.55, fill: { color: "334155" } });
  s.addText("Bulk Segment 1270 B (arrives later)", { x: 7.1, y: 1.64, w: 2.35, h: 0.55, fontSize: 9, color: MUTED, align: "center", valign: "middle", fontFace: "Calibri" });

  // Fast lane arrow for PS
  s.addText("⚡ HIGH-PRIORITY channel", { x: 5.7, y: 2.23, w: 1.4, h: 0.3, fontSize: 8, color: ACCENT1, align: "center", fontFace: "Calibri" });
  s.addText("Normal channel", { x: 7.1, y: 2.23, w: 2.35, h: 0.3, fontSize: 8, color: MUTED, align: "center", fontFace: "Calibri" });

  s.addShape(pres.shapes.LINE, { x: 6.4, y: 2.55, w: 0, h: 0.3, line: { color: ACCENT1, width: 2 } });
  s.addText("▼", { x: 6.27, y: 2.77, w: 0.26, h: 0.22, fontSize: 12, color: ACCENT1, align: "center", fontFace: "Calibri" });

  s.addShape(pres.shapes.ROUNDED_RECTANGLE, { x: 5.7, y: 2.85, w: 3.75, h: 0.55, fill: { color: "062A1A" }, rectRadius: 0.07 });
  s.addText("App starts decoding as Priority Segment arrives!", { x: 5.7, y: 2.85, w: 3.75, h: 0.55, fontSize: 10, bold: true, color: ACCENT3, align: "center", valign: "middle", fontFace: "Calibri" });

  s.addShape(pres.shapes.LINE, { x: 6.4, y: 3.4, w: 0, h: 0.28, line: { color: MUTED, width: 1, dashType: "sysDot" } });
  s.addText("▼", { x: 6.27, y: 3.6, w: 0.26, h: 0.22, fontSize: 12, color: MUTED, align: "center", fontFace: "Calibri" });

  s.addShape(pres.shapes.ROUNDED_RECTANGLE, { x: 5.7, y: 3.72, w: 3.75, h: 0.58, fill: { color: "0D1B3E" }, rectRadius: 0.07 });
  s.addText("Bulk arrives → full frame assembled\n(but decoding already started!)", { x: 5.7, y: 3.72, w: 3.75, h: 0.58, fontSize: 10, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });

  // VS divider
  s.addShape(pres.shapes.OVAL, { x: 4.55, y: 2.32, w: 0.9, h: 0.9, fill: { color: "1E3A6A" } });
  s.addText("VS", { x: 4.55, y: 2.32, w: 0.9, h: 0.9, fontSize: 16, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });

  // Result
  card(s, 0.3, 4.36, 9.4, 0.55, "0A1A2E");
  s.addText("PAFPT saves 60–75% of time-to-first-byte for video  ·  App pipelines processing  ·  Zero impact on URLLC (small packets never split)", {
    x: 0.5, y: 4.42, w: 9.0, h: 0.42, fontSize: 11, color: ACCENT3, align: "center", fontFace: "Calibri",
  });
}

// ─────────────────────────────────────────────────────────────────────────────
// SLIDE 9 – RESULTS CHART + TABLE (MB units)
// ─────────────────────────────────────────────────────────────────────────────
{
  const s = pres.addSlide();
  s.background = { color: BG };

  s.addText("Simulation Results — Proof of Concept", {
    x: 0.5, y: 0.15, w: 9, h: 0.45, fontSize: 26, bold: true, color: WHITE, fontFace: "Calibri",
  });
  s.addText("200-packet runs  ·  Python 3 + NumPy + Pandas  ·  5G / 4G / 3G channel conditions", {
    x: 0.5, y: 0.58, w: 9, h: 0.24, fontSize: 11, color: MUTED, italic: true, fontFace: "Calibri",
  });

  // Bar chart – compression ratio
  s.addChart(pres.charts.BAR, [{
    name: "Compression Ratio",
    labels: ["5G VoIP", "5G IoT", "5G Video", "4G VoIP", "3G VoIP"],
    values: [13.3, 20.0, 1.03, 13.1, 12.8],
  }], {
    x: 0.3, y: 0.9, w: 5.4, h: 3.3,
    barDir: "col",
    chartColors: ["1DA8E0", "10B981", "F97316", "1DA8E0", "60A5FA"],
    chartArea: { fill: { color: CARD }, roundedCorners: true },
    catAxisLabelColor: MUTED,
    valAxisLabelColor: MUTED,
    valGridLine: { color: "1E3A6A", size: 0.5 },
    catGridLine: { style: "none" },
    showValue: true,
    dataLabelColor: WHITE,
    dataLabelFontSize: 11,
    showLegend: false,
    showTitle: true,
    title: "Avg Compression Ratio by Profile",
    titleColor: WHITE,
    titleFontSize: 13,
  });

  // Results table
  const rows = [
    [
      { text: "Network / App",    options: { bold: true, color: WHITE, fill: { color: "1E3A6A" } } },
      { text: "Ratio",            options: { bold: true, color: WHITE, fill: { color: "1E3A6A" } } },
      { text: "MB saved/pkt",     options: { bold: true, color: WHITE, fill: { color: "1E3A6A" } } },
      { text: "Overhead",         options: { bold: true, color: WHITE, fill: { color: "1E3A6A" } } },
    ],
    ["5G VoIP",  "~13.3×", "~0.000037 MB", "60% → 5%"],
    ["5G IoT",   "~20×",   "~0.000038 MB", "67% → 4%"],
    ["5G Video", "~1.03×", "~0.000037 MB", "3% → 0.2%"],
    ["4G VoIP",  "~13.1×", "~0.000037 MB", "60% → 5%"],
    ["3G VoIP",  "~12.8×", "~0.000036 MB", "60% → 6%"],
  ];
  s.addTable(rows, {
    x: 5.85, y: 0.9, w: 3.8, h: 3.3,
    colW: [1.3, 0.85, 1.05, 0.88],
    border: { pt: 0.5, color: "1E3A6A" },
    fill: { color: CARD },
    color: WHITE,
    fontSize: 10.5,
    fontFace: "Calibri",
    align: "center",
    valign: "middle",
  });

  // Key insights
  const insights = [
    ["IoT benefits most", "Header is 67% of packet; ROHC in SO state drops it to just ~4%"],
    ["SO reached in 2 packets", "Maintained for 100+ packets continuously — very stable"],
    ["Loss handled cleanly", "IR reset triggered; context rebuilt in 2 packets — zero data lost"],
    ["Video: ~0.037 MB saved per packet", "But ratio ≈ 1× since payload (0.0014 MB) already dominates"],
  ];
  insights.forEach(([title, detail], i) => {
    const cx = i < 2 ? 0.3 : 5.1;
    const cy = 4.35 + (i % 2) * 0.6;
    const cw = 4.6;
    card(s, cx, cy, cw, 0.52, DARK);
    s.addText(`▸  ${title}:  `, { x: cx + 0.12, y: cy + 0.06, w: cw - 0.2, h: 0.22, fontSize: 11, bold: true, color: ACCENT3, fontFace: "Calibri" });
    s.addText(detail, { x: cx + 0.12, y: cy + 0.26, w: cw - 0.2, h: 0.22, fontSize: 10, color: MUTED, fontFace: "Calibri" });
  });
}

// ─────────────────────────────────────────────────────────────────────────────
// SLIDE 10 – COMPARISON TABLE (baseline vs ours)
// ─────────────────────────────────────────────────────────────────────────────
{
  const s = pres.addSlide();
  s.background = { color: BG };

  s.addText("How Our Enhancements Compare", {
    x: 0.5, y: 0.12, w: 9, h: 0.45, fontSize: 26, bold: true, color: WHITE, fontFace: "Calibri",
  });
  s.addText("Standard ROHC is the baseline — we added QASROHC and PAFPT on top of it", {
    x: 0.5, y: 0.55, w: 9, h: 0.25, fontSize: 12, color: MUTED, italic: true, fontFace: "Calibri",
  });

  const rows = [
    [
      { text: "What it does",           options: { bold: true, color: WHITE, fill: { color: "1E3A6A" } } },
      { text: "Baseline ROHC",          options: { bold: true, color: WHITE, fill: { color: "1E3A6A" } } },
      { text: "QASROHC (Our Add-on)",   options: { bold: true, color: WHITE, fill: { color: "065F46" } } },
      { text: "PAFPT (Our Add-on)",     options: { bold: true, color: WHITE, fill: { color: "065F46" } } },
    ],
    ["Main goal",              "Compress header bytes",       "Enter SO state faster",              "Deliver large payloads earlier"],
    ["Who benefits",           "All traffic equally",          "URLLC & mMTC flows",                 "Video / large frames"],
    ["How it works",           "IR→FO→SO same for everyone", "k₁,k₂ thresholds per QoS class",     "Split SDU → Priority + Bulk"],
    ["ROHC format changed?",   "Baseline",                    "No — same packets, different timing", "No — new PDCP flag only"],
    ["RLC/MAC changed?",       "No",                          "No",                                  "Priority flag → MAC queue"],
    ["Backward compatible?",   "—",                           "✔ Yes",                               "✔ Yes"],
    ["URLLC header (10 pkts)", "~0.018 MB",                   "~0.003 MB  (83% less!)",             "Not applicable"],
    ["mMTC header (10 pkts)",  "~0.018 MB",                   "~0.005 MB  (70% less!)",             "Not applicable"],
    ["Video delivery speed",   "Wait full 0.0014 MB frame",   "Not applicable",                      "60–75% faster first byte"],
  ];

  s.addTable(rows, {
    x: 0.3, y: 0.88, w: 9.4, h: 4.7,
    colW: [2.5, 2.1, 2.4, 2.4],
    border: { pt: 0.5, color: "1E3A6A" },
    fill: { color: CARD },
    color: WHITE,
    fontSize: 10.5,
    fontFace: "Calibri",
    align: "center",
    valign: "middle",
  });
}

// ─────────────────────────────────────────────────────────────────────────────
// SLIDE 11 – 20-SECOND VIVA EXPLANATION (from the PDF)
// ─────────────────────────────────────────────────────────────────────────────
{
  const s = pres.addSlide();
  s.background = { color: BG };

  s.addText("20-Second Viva Explanation", {
    x: 0.5, y: 0.15, w: 9, h: 0.48, fontSize: 28, bold: true, color: WHITE, fontFace: "Calibri",
  });
  s.addText("Use this if the evaluator says: \"Explain your project in one minute\"", {
    x: 0.5, y: 0.62, w: 9, h: 0.28, fontSize: 12, color: MUTED, italic: true, fontFace: "Calibri",
  });

  const points = [
    { icon: "1", color: RED,    title: "ROHC has 3 states: IR, FO, and SO", body: "IR sends the full header. FO sends only what changed. SO lets the receiver predict everything — header shrinks to 1–3 bytes = 0.001–0.003 MB." },
    { icon: "2", color: ACCENT2, title: "Standard ROHC uses the same transition speed for all traffic", body: "An emergency URLLC packet and a YouTube video chunk both wait the same number of packets before reaching SO — inefficient!" },
    { icon: "3", color: ACCENT3, title: "Our QASROHC makes the transition speed adaptive", body: "URLLC and mMTC reach SO immediately (k₁=1, k₂=1). Header overhead drops by ~83% for URLLC in the critical first 10 packets." },
    { icon: "4", color: ACCENT1, title: "Our PAFPT splits large payloads into two segments", body: "A small Priority Segment (header + first bytes) arrives first and decoding starts immediately. The Bulk Segment follows normally — 60–75% faster first-byte delivery." },
  ];

  points.forEach(({ icon, color, title, body }, i) => {
    const y = 1.06 + i * 1.08;
    s.addShape(pres.shapes.OVAL, { x: 0.35, y: y + 0.18, w: 0.52, h: 0.52, fill: { color } });
    s.addText(icon, { x: 0.35, y: y + 0.18, w: 0.52, h: 0.52, fontSize: 16, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });
    s.addShape(pres.shapes.ROUNDED_RECTANGLE, { x: 1.0, y, w: 8.7, h: 0.96, fill: { color: DARK }, rectRadius: 0.07 });
    s.addText(title, { x: 1.15, y: y + 0.05, w: 8.4, h: 0.34, fontSize: 13, bold: true, color, fontFace: "Calibri" });
    s.addText(body, { x: 1.15, y: y + 0.38, w: 8.4, h: 0.52, fontSize: 11, color: MUTED, fontFace: "Calibri" });
  });
}

// ─────────────────────────────────────────────────────────────────────────────
// SLIDE 12 – PROJECT STATUS & NEXT STEPS
// ─────────────────────────────────────────────────────────────────────────────
{
  const s = pres.addSlide();
  s.background = { color: BG };

  s.addText("Project Status & Next Steps", {
    x: 0.5, y: 0.15, w: 9, h: 0.48, fontSize: 28, bold: true, color: WHITE, fontFace: "Calibri",
  });

  const phases = [
    { ph: "Ph 1–2", label: "Planning & Literature Review",        done: true  },
    { ph: "Ph 3",   label: "System Design & Block Diagram",       done: true  },
    { ph: "Ph 4–5", label: "Simulation + ROHC Implementation",    done: true  },
    { ph: "Ph 6",   label: "Testing & Validation",                done: true  },
    { ph: "Ph 7",   label: "Full Performance Analysis",           done: true  },
    { ph: "Ph 8–9", label: "Visualisation & IEEE Draft Paper",    done: false },
    { ph: "Ph 10",  label: "Final Report & Submission",           done: false },
  ];

  phases.forEach(({ ph, label, done }, i) => {
    const y = 0.8 + i * 0.6;
    const color = done ? ACCENT3 : ORANGE;
    s.addShape(pres.shapes.OVAL, { x: 0.4, y: y + 0.06, w: 0.44, h: 0.44, fill: { color } });
    s.addText(done ? "✔" : "⟳", { x: 0.4, y: y + 0.06, w: 0.44, h: 0.44, fontSize: 14, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri" });
    s.addText(ph, { x: 1.0, y, w: 1.2, h: 0.44, fontSize: 13, bold: true, color: done ? ACCENT3 : ORANGE, fontFace: "Calibri", valign: "middle", margin: 0 });
    s.addText(label, { x: 2.35, y, w: 6.0, h: 0.44, fontSize: 13, color: WHITE, fontFace: "Calibri", valign: "middle", margin: 0 });
    s.addText(done ? "COMPLETE" : "UPCOMING", { x: 8.4, y: y + 0.06, w: 1.25, h: 0.32, fontSize: 10, bold: true, color: done ? ACCENT3 : ORANGE, align: "center", fontFace: "Calibri" });
  });

  card(s, 0.4, 5.08, 9.2, 0.42, DARK);
  s.addText("Final Submission: 20 May 2026  ·  Remaining: IEEE paper draft, 4 publication-quality graphs, complete documentation", {
    x: 0.6, y: 5.14, w: 8.8, h: 0.3, fontSize: 11, color: ACCENT2, align: "center", fontFace: "Calibri",
  });
}

// ─────────────────────────────────────────────────────────────────────────────
// SLIDE 13 – THANK YOU
// ─────────────────────────────────────────────────────────────────────────────
{
  const s = pres.addSlide();
  s.background = { color: BG };

  s.addShape(pres.shapes.RECTANGLE, { x: 0, y: 0, w: 10, h: 0.06, fill: { color: ACCENT1 } });

  s.addText("Thank You", {
    x: 0.5, y: 1.3, w: 9, h: 1.0, fontSize: 56, bold: true, color: WHITE,
    align: "center", fontFace: "Calibri",
  });
  s.addText("Open for Questions", {
    x: 0.5, y: 2.35, w: 9, h: 0.48, fontSize: 22, color: ACCENT1,
    align: "center", fontFace: "Calibri",
  });

  const stats = [
    ["~20×",      "Compression ratio\n(5G IoT traffic)"],
    ["0.001 MB",  "SO-state header\n(down from 0.039 MB)"],
    ["~83%",      "QASROHC gain\nfor URLLC latency"],
    ["60–75%",    "PAFPT faster\nfirst-byte delivery"],
  ];
  stats.forEach(([val, lbl], i) => {
    statBox(s, 0.35 + i * 2.33, 3.25, 2.15, val, lbl, ACCENT3);
  });

  s.addText("KLE Technological University  ·  ECE Department  ·  Minor Project Review 3  ·  2025–26", {
    x: 0.5, y: 5.1, w: 9, h: 0.28, fontSize: 10, color: MUTED, align: "center", fontFace: "Calibri",
  });

  s.addShape(pres.shapes.RECTANGLE, { x: 0, y: 5.52, w: 10, h: 0.1, fill: { color: ACCENT2 } });
}

pres.writeFile({ fileName: "/home/claude/ROHC_Review3_PPT.pptx" }).then(() => {
  console.log("Done");
}).catch(e => console.error(e));