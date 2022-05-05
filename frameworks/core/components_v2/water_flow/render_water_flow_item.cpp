/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "core/components_v2/water_flow/render_water_flow_item.h"

#include "base/utils/utils.h"
#include "core/components_v2/water_flow/render_water_flow.h"
#include "core/components_v2/water_flow/water_flow_item_component.h"

namespace OHOS::Ace::V2 {
RefPtr<RenderNode> RenderWaterFlowItem::Create()
{
    return AceType::MakeRefPtr<RenderWaterFlowItem>();
}

void RenderWaterFlowItem::Update(const RefPtr<Component>& component)
{
    const RefPtr<V2::WaterFlowItemComponent> flowItem = AceType::DynamicCast<V2::WaterFlowItemComponent>(component);
    if (!flowItem) {
        return;
    }
    SetColumnSpan(flowItem->GetColumnSpan());
    SetRowSpan(flowItem->GetRowSpan());
    SetForceRebuild(flowItem->ForceRebuild());
    onSelectId_ = flowItem->GetOnSelectId();
    selectable_ = flowItem->GetSelectable();
    MarkNeedLayout();
}

void RenderWaterFlowItem::PerformLayout()
{
    if (GetChildren().empty()) {
        LOGE("RenderWaterFlowItem: no child found in RenderWaterFlowItem!");
    } else {
        auto child = GetChildren().front();
        child->Layout(GetLayoutParam());
        child->SetPosition(Offset::Zero());
        SetLayoutSize(child->GetLayoutSize());
    }
}

void RenderWaterFlowItem::HandleOnFocus()
{
    auto parent = GetParent().Upgrade();
    while (parent) {
        auto waterFlow = AceType::DynamicCast<RenderWaterFlow>(parent);
        if (waterFlow) {
            waterFlow->UpdateFocusInfo(index_);
            break;
        }
        parent = parent->GetParent().Upgrade();
    }
}

void RenderWaterFlowItem::SetColumnSpan(int32_t columnSpan)
{
    if (columnSpan <= 0) {
        LOGW("Invalid columnSpan %{public}d", columnSpan);
        return;
    }
    columnSpan_ = columnSpan;
}

void RenderWaterFlowItem::SetRowSpan(int32_t rowSpan)
{
    if (rowSpan <= 0) {
        LOGW("Invalid rowSpan %{public}d", rowSpan);
        return;
    }
    rowSpan_ = rowSpan;
}
} // namespace OHOS::Ace::V2
