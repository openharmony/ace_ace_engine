/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
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

#ifndef FOUNDATION_ACE_FRAMEWORKS_CORE_COMPONENTS_STEPPER_FLUTTER_RENDER_STEPPER_ITEM_H
#define FOUNDATION_ACE_FRAMEWORKS_CORE_COMPONENTS_STEPPER_FLUTTER_RENDER_STEPPER_ITEM_H

#include "core/components/stepper/render_stepper_item.h"

#include "core/pipeline/layers/clip_layer.h"

namespace OHOS::Ace {

class FlutterRenderStepperItem : public RenderStepperItem {
    DECLARE_ACE_TYPE(FlutterRenderStepperItem, RenderStepperItem);

public:
    RenderLayer GetRenderLayer() override;
    void Paint(RenderContext& context, const Offset& offset) override;

private:
    RefPtr<Flutter::ClipLayer> layer_;
};

} // namespace OHOS::Ace

#endif // FOUNDATION_ACE_FRAMEWORKS_CORE_COMPONENTS_STEPPER_FLUTTER_RENDER_STEPPER_ITEM_H
