# Design System Specification (DESIGN.md)
## Examination Results Monitoring System

*Generated following the Impeccable Design Skill standard for institutional academic interfaces.*

---

### 🎨 Color Palette & Semantic Tokens

| Token Role | Hex Color | Description & Application |
| :--- | :--- | :--- |
| **Canvas Background** | `#F1F5F9` (Slate-100) | Main application workspace canvas |
| **Card / Surface** | `#FFFFFF` (White) | Content panels, card containers, dialog backgrounds |
| **Deep Nav / Header** | `#0F172A` (Slate-900) | Top bar, sidebar brand container, table headers |
| **Sidebar Surface** | `#1E293B` (Slate-800) | Left navigation sidebar background |
| **Nav Hover State** | `#334155` (Slate-700) | Interactive sidebar hover state |
| **Border Normal** | `#E2E8F0` (Slate-200) | Subtle container and grid line borders |
| **Text Primary** | `#0F172A` (Slate-900) | High-contrast body, headings, and metric labels |
| **Text Secondary** | `#64748B` (Slate-500) | Field labels, captions, metadata descriptions |
| **Primary Action** | `#0284C7` (Sky-600) | Main action buttons (Register, Save, Sign In) |
| **Primary Hover** | `#0369A1` (Sky-700) | Primary button hover state |
| **Primary Active** | `#075985` (Sky-800) | Primary button mouse-down state |
| **Success / Approved** | `#16A34A` (Green-600) | Authorize, calculate, and Senate-approved indicators |
| **Success Hover** | `#15803D` (Green-700) | Success button hover state |
| **Danger / Overdue** | `#DC2626` (Red-600) | Sign out, critical alerts, and deadline violations |
| **Danger Hover** | `#B91C1C` (Red-700) | Danger button hover state |
| **Warning / Moderation** | `#D97706` (Amber-600) | Pending milestones, moderation in progress |
| **Teal / Diagnostics** | `#0D9488` (Teal-600) | Data export, DML generators |

---

### 🔠 Typography Hierarchy

* **Font Family:** `Segoe UI` (native, highly legible on all Windows display scaling).
* **Code / SQL Editor:** `Consolas` 10.0pt.
* **Scale:**
  * **Hero Metric Display:** `Segoe UI Bold` 17.0pt (`#0F172A`).
  * **Window Headings:** `Segoe UI Semibold` 15.5pt (`#FFFFFF`).
  * **Section Headings:** `Segoe UI Semibold` 12.0pt (`#0F172A`).
  * **Card Labels / Headers:** `Segoe UI Semibold` 9.5pt (`#334155`).
  * **Table Cells & Inputs:** `Segoe UI` 9.0pt (`#1E293B`).
  * **Subtitles & Badges:** `Segoe UI Semibold` 7.5pt–8.5pt.

---

### 📊 DataGridView Enterprise Styling Standard

All 8 system DataGridViews adhere to the unified `StyleDataGridView` specification:
- **`EnableHeadersVisualStyles = false`**: Bypasses Windows classic rendering to support custom themes.
- **Header Background:** `#0F172A` with `#FFFFFF` text.
- **Row Alternation:** `#FFFFFF` alternating with `#F8FAFC`.
- **Selection Highlight:** Soft `#E0F2FE` (Sky-100) with `#0F172A` dark text for superior contrast.
- **Cell Padding:** `Padding(8, 4, 8, 4)` with `RowTemplate.Height = 32`.
- **Grid Lines:** Clean `#E2E8F0` horizontal divider rules.
- **Dynamic Cell Formatting:**
  - `🔴 CRITICAL DELAY`: Soft red background `#FEE2E2` with `#B91C1C` bold text.
  - `🟡 PROCEDURAL GATE`: Soft yellow background `#FEF9C3` with `#A16207` bold text.

---

### 🖱️ Interaction & Micro-Feedback Behaviors

1. **Button Cursors:** Every interactive button sets `Cursor = Cursors::Hand`.
2. **Flat Appearance Hover Colors:**
   - Every button explicitly specifies `MouseOverBackColor` and `MouseDownBackColor` matched to its semantic color family.
3. **Workflow Step Actions (Tab 7):**
   - Left-aligned, numbered action buttons with visual hover states (`#E0F2FE`) and step indicators.
4. **Responsive Top Bar Layout:**
   - Top right controls are grouped in a dedicated anchor panel to prevent collisions on any resolution.
5. **Real-time Sum Indicator (Tab 8):**
   - Automatically validates Continuous Assessment + Final Exam weights on every input tick, providing instantaneous visual feedback (`✓ Valid` in Green vs `✗ Invalid` in Red).
